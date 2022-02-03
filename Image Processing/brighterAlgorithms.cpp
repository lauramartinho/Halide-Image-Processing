// Include Halide
#include "Halide.h"

// Suporte imagens png
#include "halide_image_io.h"

using namespace Halide;
using namespace Halide::Tools;

void brightOriginal(int factor) {
 
    Buffer<uint8_t> input = load_image("images/rgb.png");

    // Dimensão imagem
    printf("\n Input Image: Width: %d, Height:%d, Channels: %d\n", input.width(), input.height(), input.channels());

    // Algoritmo
    Halide::Func brighter("brightOriginal");
    Halide::Var x("x"), y("y"), c("c");
    Halide::Var x_outer("x_outer"), x_inner("x_inner"), y_outer("y_outer"), y_inner("y_inner");
    
    Halide::Expr value = input(x, y, c);
    value = Halide::cast<int>(value);

    value = value + factor;
    value = Halide::min(value, 255.0f);
    value = Halide::cast<uint8_t>(value);

    brighter(x, y, c) = value;

    // Scheduler
    Halide::Buffer<uint8_t> output =
        brighter.realize({ input.width(), input.height(), input.channels() });

    //  Salva saída
    save_image(output, "images/outputs/Aula06/Halide_brightOriginal.png");

    
    brighter.print_loop_nest();
    printf("\n Success Bright Original!\n");

};

void brightTiled(int factor) {

    Buffer<uint8_t> input = load_image("images/rgb.png");

    printf("\n Input Image: Width: %d, Height:%d, Channels: %d\n", input.width(), input.height(), input.channels());

    // Algorithm 
    Halide::Func brighter("brightTiled");
    Halide::Var x("x"), y("y"), c("c");
    Halide::Var x_outer("x_outer"), x_inner("x_inner"), y_outer("y_outer"), y_inner("y_inner");

    Halide::Expr value = input(x, y, c);
    value = Halide::cast<int>(value);

    value = value + factor;
    value = Halide::min(value, 255.0f);
    value = Halide::cast<uint8_t>(value);

    brighter(x, y, c) = value;

    // Scheduler 02
    brighter.tile(x, y, x_outer, y_outer, x_inner, y_inner, 4, 4);
    brighter.reorder(c, x_inner, y_inner, x_outer, y_outer);


    Halide::Buffer<uint8_t> output =
        brighter.realize({ input.width(), input.height(), input.channels() });

    
    save_image(output, "images/outputs/Aula06/Halide_brightTiled.png");

    
    brighter.print_loop_nest();
    printf("\n Success Bright Original!\n");

};

void brightVector(int factor) {
    
    Buffer<uint8_t> input = load_image("images/rgb.png");

    printf("\n Input Image: Width: %d, Height:%d, Channels: %d\n", input.width(), input.height(), input.channels());

    Halide::Func brighter("brightVector");
    Halide::Var x("x"), y("y"), c("c");
    Halide::Var x_outer("x_outer"), x_inner("x_inner"), y_outer("y_outer"), y_inner("y_inner");

    Halide::Expr value = input(x, y, c);
    value = Halide::cast<int>(value);

    value = value + factor;
    value = Halide::min(value, 255.0f);
    value = Halide::cast<uint8_t>(value);

    brighter(x, y, c) = value;

    // Scheduler 03
    brighter.split(y, y_outer, y_inner, 8).vectorize(y_inner).parallel(c);


    Halide::Buffer<uint8_t> output =
        brighter.realize({ input.width(), input.height(), input.channels() });

     
    save_image(output, "images/outputs/Aula06/Halide_brightVector.png");

    brighter.print_loop_nest();
    printf("\n Success Bright Original!\n");

};

void brightParallel(int factor) {
    
    Buffer<uint8_t> input = load_image("images/rgb.png");

    printf("\n Input Image: Width: %d, Height:%d, Channels: %d\n", input.width(), input.height(), input.channels());

    // Algorithm 
    Halide::Func brighter("brightParallel");
    Halide::Var x("x"), y("y"), c("c");
    Halide::Var x_outer("x_outer"), x_inner("x_inner"), y_outer("y_outer"), y_inner("y_inner");

    Halide::Expr value = input(x, y, c);
    value = Halide::cast<int>(value);

    value = value + factor;
    value = Halide::min(value, 255.0f);
    value = Halide::cast<uint8_t>(value);

    brighter(x, y, c) = value;

    // Scheduler 04

    brighter
        .reorder(x, c, y)
        .split(x, x_outer, x_inner, 32)
        .parallel(c)
        .vectorize(x_inner);

    Halide::Buffer<uint8_t> output =
        brighter.realize({ input.width(), input.height(), input.channels() });

    save_image(output, "images/outputs/Aula06/Halide_brightParallel.png");

    brighter.print_loop_nest();
    printf("\n Success Bright Original!\n");

};



int main(int argc, char** argv) {

    //Buffer<uint8_t> input = load_image("images/rgb.png");

    brightOriginal(11);
    //brightReorder(11);
    brightVector(11);
    brightTiled(11);
    brightParallel(11);
    
    printf(" \n End Success!\n");
    return 0;
}
