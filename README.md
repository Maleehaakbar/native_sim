# native_sim

1. setup native sim simulator 
2. test hello world
3. test different color depth //sdl2 doesnt support 1-bit monochrome 
4. test multiple screens ...
5. see how callbacks work //TODO
6. integarte different images

smart watch features
1. shows the current time, date, battery life, weather, and step counter.
2. Migration to newer version of lvgl/nrfconnect sdk

nrf connect features
nordic MCP

Imp points:
1. in lvgl , images can be stored two places
as a variable in internal memory (RAM or ROM)
as a file

Images stored as files are not linked into the resulting executable, and must be read into RAM before being drawn. As a result, they are not as resource-friendly as images linked at compile time. However, they are easier to replace without needing to rebuild the main program

2. convert image to c array to use in lvgl code

