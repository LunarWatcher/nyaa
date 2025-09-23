# Project structure

* `3p-patches`: Contains `.patch` files for dependencies sourced with FetchContent
* `assets`: Contains both raw assets (`.aseprite`) and exported assets (`.png`, `.json`). 
* `docs`: Documentation. What do you expect?
* `src`: The code. There's no particular architecture in this folder, however:
    * `src/nyaa/engine`: Contains the engine. These files ***CANNOT*** depend on files in any other folders. The engine must remain self-contained, so it can potentially be split out into its own project.
    * The other folders contain the game-specific files. These may be detailed more here in the future.
* `tests`: Contains all the automated tests for the project

