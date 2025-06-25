
  **OBJECTS AND CLASSES**

 => Class is a user defined data type that acts as a blueprint for creating its instances or objects.
   in c++ classes are created using the  'class' keyword .
   **Syntax for class creation** :

                 class  classname{
                        
                        #class definition

                 };

 => In Object-Oriented Programming, an object is an instance of a class, and it represents a real-world       entity with state and behavior.


 **VIRTUAL AND NATIVE LANGUAGE**
 => A native language refers to code or instructions comiled to run directly on the hardware or nativel
    y on the operating system eithour requiring any additional layers like interpreters and virtual machines.

=> A virtual language on other hand runs on a virtual machine, rather than directly on the hardware.
   An intermediate software layer(virtual machines or runtime enviroment) helps to abstract the underlying 
   platform, making the language more portable but often less efficient .



**HOW C++ WORKS**
=>A C++ source code gets converted into executable machine level code going through the following stages :
1.Source Code
2.Preprocessing
3.Compilation
4.Linking
5.Execution

  **Preprocessing**
=>All the macros and conditional directives are resolved and expanded.
=>The preprocessor generates a combined and expanded source file thats ready for the compiler.

   **Compilation**
=>The compiler is handled the preprocessed code and it performs the following operations :
  i.Lexiacal analysis : converts the code into tokens.
  ii.Syntax analysis building a parse tree.
  iii.Semantic analysis : checks types and scopes.
  iv.converts the preprocessed code to object codes and places in a .o or .obj file
  V.The main stage also sometimes considered different than compiling includes ASSEMBLING, which converts the assembly code generated into machine code and the resukt is stored into object files .

  ****
