Rify's C Game FrameWork (RCGFW) is an OpenGL wrapper and game creation framework entirely written in C.

##### Rewrite Numero Tres

# RCGFW 0.0.1 - The Display
RCGFW 0.0.1 introduces the GLFW display and OpenGL context to the engine.  This update also brings a File IO wrapper and a Resource Manager to RCGFW, setting up shader loading and other types of file loading in future versions.

### Changelog
- GLFW Display is created and runs through a loop
- GLAD creates the GL context required for future rendering
- File IO
    + Ability to read from a file easily.
    + Ability to write to a file easily.
- Resource Manager
    + Does nothing at the moment, will be addressed in v0.0.2

# RCGFW 0.0.2 - Rendering
- Shaders
    + Resource manager loads shader files
    + Shader source code is compiled into a shader
    + Shaders are stored in the framework's state
    + Shaders can be pulled from the state for easier shader management