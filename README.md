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

#### 4.1 Creating a new empty project
   
   [<img src="https://user-images.githubusercontent.com/65466643/152353955-fc2dae8e-c434-4e2a-8280-4cd35ce9910a.png" width="470"/>](image.png)
   
   Change to Release mode and correct windows version
   
   [<img src="https://user-images.githubusercontent.com/65466643/152354713-1d3e33b5-c6f2-42a1-bd52-a86609327db2.png" width="600"/>](image1.png)
   
   Create a cpp file 
   
   [<img src="https://user-images.githubusercontent.com/65466643/152357703-839541c1-103a-4921-9296-ad8c4b86d474.png" width="500"/>](image6.png)
   [<img src="https://user-images.githubusercontent.com/65466643/152357723-2476cba6-90cc-410a-b699-4729b7a6e3c1.png" width="450"/>](image7.png)
   
   Now, run the project on Local Windows Debugger. It will return error because you´re running nothing, but don´t worry, for now we only need the generated windows release folder in the project local files.
   
   #
   #### 4.2. Files management
   
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
   
  Last work with local files, we need to bring the dlls to the project directory. They can be found in the Halide and Vcpkg bin folders. jpeg and png lib dll files at ```vcpkg\installed\x64-windows\bin``` and Halide lib dll files at ```Halidex64\bin\Release```. Copy all of the .dll files found and paste it inside your Project windows file ```HalideProject\Teste\x64\Release```.
  
   [<img src="https://user-images.githubusercontent.com/65466643/152376273-4a701798-fa6a-4b7d-bf31-436471ff15de.png" width="500"/>](image14.png)
   [<img src="https://user-images.githubusercontent.com/65466643/152376263-7a791750-3071-4bf6-a35c-5916539928a3.png" width="500"/>](image13.png)
  
  Copy all that .dll files from each folders to the windows folder on project directory ```HalideProject\Teste\x64\Release```.
  
  This is what we get:
  
  [<img src="https://user-images.githubusercontent.com/65466643/152377515-12b68c81-af2b-4936-8ef0-2942ea317520.png" width="320"/>](image15.png)
  
  #
  
#### 4.3. Back to Visual studio last configurations

Open project properties

[<img src="https://user-images.githubusercontent.com/65466643/152379394-233f0efa-2fbd-42b2-9675-c9e89d47308c.png" width="450"/>](image20.png)

Change the platform Toolset for the Clang build tools and C++ language 17 support.

[<img src="https://user-images.githubusercontent.com/65466643/152383700-736a0c41-8512-4d0d-92e9-a638e7c9adc5.png" width="520"/>](image21.png)

Allow vcpkg intall libraries but disable AutoLink.

[<img src="https://user-images.githubusercontent.com/65466643/152383842-e52de0d7-1597-4718-9b27-f14434be7571.png" width="520"/>](image22.png)

In vc++ directories, edit the include field with your include folder created on step [4.2](#4.2.-Files-management) directory, add ```Halidex64\share\Halide\tools``` either. In library field, edit to the libraries folder dirctory. 

[<img src="https://user-images.githubusercontent.com/65466643/152381028-81f015ff-4e30-4c2d-8648-5f8194a14f55.png" width="550"/>](image23.png)

Add include folder to additional include packages too.

[<img src="https://user-images.githubusercontent.com/65466643/152382384-38f72b98-b228-4d1c-9f31-fdf11ffcfc7c.png" width="550"/>](image30.png)

Add libraries folder to additional library packages too.

[<img src="https://user-images.githubusercontent.com/65466643/152382431-ffe7c29d-cb39-4f33-a66d-461c6d9fca80.png" width="550"/>](image31.png)


Add the libraries calls on the linker: ```Halide.lib```, ```jpeg.lib``` and ```libpng16.lib```

[<img src="https://user-images.githubusercontent.com/65466643/152382442-6f650353-3901-4ed9-bf9a-d9c242fd656a.png" width="550"/>](image32.png)

**Apply all changes** 

#

### 5. Now we ae ready to start coding!

#
### Additonals

#### Visual Studio necessary Packages

[<img src="https://user-images.githubusercontent.com/65466643/152351052-a5cbd28c-3099-47fe-a0d3-81074338989e.png" width="500"/>](image2.png)

[<img src="https://user-images.githubusercontent.com/65466643/152351059-9662eb47-3da3-4fbb-b3fe-f07c9c4894dc.png" width="500"/>](image3.png)

[<img src="https://user-images.githubusercontent.com/65466643/152351074-0d985808-e10b-48fb-866f-9c01095cad38.png" width="500"/>](image4.png)

---
#### Author

<a href="https://github.com/lauramartinho">
 <img style="border-radius: 50%;" src="https://user-images.githubusercontent.com/65466643/143616931-de8587f0-bfb6-4015-8969-9df896c25247.jpg" width="80px;" alt=""/>
 <br />
 <sub><b>Laura Martinho</b></sub></a> <a href="https://github.com/lauramartinho//" title="Laura Martinho">🦕</a>
