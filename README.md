# RTv1
Simple ray tracing program

Unlike previous wolf3d project, here rays are casted in 3-dimensional system and objects have proper (even thou simple) shading.
It was required to implement ray tracing of 4 types of parametrically created primitives: plane, sphere, infinite cylinder and infinite cone. Light as simple 360 degrees emitting point source.

Bonus points were assigned for support of multiple light sources and shine effect. I could achieve both, but shine effect is done with small "hack" instead of proper specular shading.

This project requires School 42 homebrew minilibX library (included) and was only tested in macOS El Capitan / Sierra environment.

Please, compile using Makefile (type 'make' in console while in project folder)
./test_maps folder provides some examples to test on

**Example 1. It will launch red sphere with 1 pointlight**
> ./rtv1

**Example 2. This will launch scene with different objects and multiple light sources**
> ./rtv1 3

Parameter for scene selection accepts either nothing (for scene 0) or 1, 2, 3, 4, 5 and 666. I left last one as 'playground' for further experiments.

Controls:
- **NUM_8 / NUM_2** control camera pitch
- **NUM_7 / NUM_9** control camera roll
- **NUM_4 / NUM_6** control camera yaw
- **NUM_1 / NUM_3** control camera field of view (works sort of like zoom in/out)
- **ESC** exits the program. Can also be achieved by pressing red button in program's header
