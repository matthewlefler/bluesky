# bluesky

This is a work in progress project

TODOs:
1. parse arbitrary `vk.xml`
    - fix depends statment parsing so that (hi,hi_2+hi_3) is valid
    - get compiler to like outputed files
2. create pipeline
3. create spirv from shaders automatically
    - tag with spirv extension requirements
4. tag pipeline sections with what features they need
    - custom function loader possibly
    - custom preproccesing possibly
5. deal with swapping in and out portions of a pipeline to meet hardware extension avalibility
    - mix/match shaders accordingly