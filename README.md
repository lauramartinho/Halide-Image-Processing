## Halide-Image-Processing
> **Repository with Halide programming language basics and Image Processing practices.**
### 📌 Halide Windows Microsoft Visual Studio configuration 
**Must-have applications:**
   * [Microsoft Visual Studio](https://visualstudio.microsoft.com/downloads/) - C++ Clang and English language packages needed. See what to install [here](#visual-studio-packages).
   * [Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)

⚠ Attention to windows version, if x64 or x32 bits, important to download releases according to right version.
#
### 1. First, download [binary release of Halide](https://github.com/halide/Halide/releases)
### 2. Then, download [vcpkg](https://vcpkg.io/en/getting-started.html)
   
   **Step 1: Clone github repo**
   ```
   dir\user> git clone https://github.com/Microsoft/vcpkg.git
   ``` 
   **Step 2: Run the bootstrap script to build vcpkg**
   ```
   dir\user> .\vcpkg\bootstrap-vcpkg.bat
   ```
   **MSBuild / Visual Studio vcpkg install**
   ```
   dir\user>vcpkg> .\vcpkg integrate install
   ```
### 3. Install Necessary Libraries: 
   
   **Libraries needed: libjpeg-turbo and libpng. Run in vcpkg directory**
   ##### see these and other packages at [vcpkg packages section](https://vcpkg.io/en/packages.html)
   ```
   dir\user>vcpkg> .\vcpkg install libpng:x64-windows libjpeg-turbo:x64-windows llvm[target-all,clang-tools-extra]:x64-windows
   ``` 
   
### 4. Now configure MS Visual Studio
   
   Creating a new empty project
   
   [<img src="https://user-images.githubusercontent.com/65466643/152353955-fc2dae8e-c434-4e2a-8280-4cd35ce9910a.png" width="470"/>](image.png)
   
   Change to Release mode and correct windows version
   
   [<img src="https://user-images.githubusercontent.com/65466643/152354713-1d3e33b5-c6f2-42a1-bd52-a86609327db2.png" width="600"/>](image1.png)
   
   Create a cpp file 
   
   [<img src="https://user-images.githubusercontent.com/65466643/152357703-839541c1-103a-4921-9296-ad8c4b86d474.png" width="500"/>](image6.png)
   [<img src="https://user-images.githubusercontent.com/65466643/152357723-2476cba6-90cc-410a-b699-4729b7a6e3c1.png" width="450"/>](image7.png)
   
   Now, run the project on Local Windows Debugger. It will return error because you´re running nothing, but don´t worry, for now we only need the generated windows release folder in the project local files.
   
   At project files directory, create two folders where the includes and libraries files will be stored.
   
   [<img src="https://user-images.githubusercontent.com/65466643/152358747-831bd0a6-5f1b-41ce-8bd9-15bff2fc4788.png" width="450"/>](image8.png)
   
   Now we need to collect all include files and all libraries files that are going to be needed, wich are Halide libraries and the jpeg and png libraries that we downloaded. Let´s do that by searching for these files directories. Right after finding it, we are going to copy the files to our created folders.
   
   We can find Halide sources in the unzipped folder dowloaded in the first step. See include files at ```HalideFolder\include``` and lib files at ```HalideFolder\lib\Release```. Vcpkg files found at ```vcpkg\installed\windows\include``` and ```vcpkg\installed\windows\lib```.
   
   [<img src="https://user-images.githubusercontent.com/65466643/152362135-08f0f04a-ca4a-41aa-bd0d-4500c062d89b.png" width="450"/>](image9.png)
   [<img src="https://user-images.githubusercontent.com/65466643/152363659-58e98564-30b6-46dc-a37b-016d1c6333ae.png" width="400"/>](image10.png)

   Then, copy **all** the *include files* from **each folder** and **paste it inside the include folder you created**. Do the same with the **lib files**, copy all of them from each of the lib file folders and paste it inside the **libraries** folder you created ate the project directory.
   
   We are going to have something like this:
   
   [<img src="https://user-images.githubusercontent.com/65466643/152368879-4e67c286-9939-43bb-972b-ff4de1aaa003.png" width="600"/>](image12.png)
   
   [<img src="https://user-images.githubusercontent.com/65466643/152368866-2b0d051e-a730-4468-bd6f-7e357c98f9d5.png" width="600"/>](image11.png)
   
  Last work with local files, we need to bring the dlls to the project directory. They can be found in the Halide and Vcpkg bin folders.


#
### Visual Studio Packages
[<img src="https://user-images.githubusercontent.com/65466643/152351052-a5cbd28c-3099-47fe-a0d3-81074338989e.png" width="470"/>](image2.png)
[<img src="https://user-images.githubusercontent.com/65466643/152351059-9662eb47-3da3-4fbb-b3fe-f07c9c4894dc.png" width="470"/>](image3.png)
[<img src="https://user-images.githubusercontent.com/65466643/152351074-0d985808-e10b-48fb-866f-9c01095cad38.png" width="470"/>](image4.png)

---
#### Author

<a href="https://github.com/lauramartinho">
 <img style="border-radius: 50%;" src="https://user-images.githubusercontent.com/65466643/143616931-de8587f0-bfb6-4015-8969-9df896c25247.jpg" width="80px;" alt=""/>
 <br />
 <sub><b>Laura Martinho</b></sub></a> <a href="https://github.com/lauramartinho//" title="Laura Martinho">🦕</a>
