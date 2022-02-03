/* 
Computação Paralela Usando Halide
CODIGO : Halide RGB2Gray
Laura Martinho
*/

#include "Halide.h"
#include "halide_image_io.h"

using namespace Halide;
using namespace Halide::Tools;

int main(int argc, char** argv){
    
    uint16_t R2GRAY = 77, G2GRAY = 150, B2GRAY = 29;

    //declare function
    Func rgb2gray("rgb2gray");
   
    //Load Image from your input folder
    Halide::Buffer<uint8_t> input = load_image("input/image.png");

    Var x("x"), y("y");

    
    //Algorithm 
    Expr r = cast<uint16_t>(input(x, y, 0));
    Expr g = cast<uint16_t>(input(x, y, 1));
    Expr b = cast<uint16_t>(input(x, y, 2));
    rgb2gray(x, y) = cast<uint8_t>((R2GRAY * r + G2GRAY * g + B2GRAY * b) >> 8);


    //Scheduler
    Halide::Var x_outer("x_outer"), x_inner("x_inner"), y_outer("y_outer"), y_inner("y_inner"), tile_index("tile_index");

    rgb2gray.tile(x, y, x_outer, y_outer, x_inner, y_inner, 4, 4);
    rgb2gray.fuse(x_outer, y_outer, tile_index);
    rgb2gray.parallel(tile_index);
    rgb2gray.get_schedule();
    rgb2gray.print_loop_nest();
    
    Halide::Target target = Halide::get_host_target();
    target.set_feature(Target::Feature::CUDA, true);

    Halide::Buffer<uint8_t> output =
        rgb2gray.realize({ input.width(), input.height(), input.channels() });

    rgb2gray.print_loop_nest(); 

    //Save result in your output folder
    save_image(output, "outputs/rgb2gray.png");

    printf("Success!\n");
    return 0;
}
