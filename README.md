## Halide-Image-Processing
#### Repository with Halide programming language **basics** and **Image Processing practices**.
### 📌 Halide Microsoft Visual Studio configuration 
#### ⚠ Attention to windows version, if x64 or x32 bits, important to download releases according to right version.
#### 1. First, download binary release of Halide in: https://github.com/halide/Halide/releases
#### 2. Then, download vcpkg: https://vcpkg.io/en/getting-started.html
##### -> Notice that git is needed. (https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)
#### 3. Install Necessary Libraries: 
#### - Libraries needed: libjpeg-turbo and libpng. Run in vcpkg directory:

~~~
$ users > vcpkg > .\vcpkg install libpng:x64-windows libjpeg-turbo:x64-windows llvm[target-all,clang-tools-extra]:x64-windows
   ~~~~
##### (see these and other packages at: https://vcpkg.io/en/packages.html)
#### 4. Now configure MS Visual Studio
