# Assets

This folder contains the various assets, including the raw `.aseprite` files. 

This folder contains a mix of exported and non-exported files. Only the `.json` and `.png` files are exported during the build, as `.aseprite` is a proprietary format without any C/C++-based parsers[^1], so it has no value at runtime.

## Export requirements

The exports are assumed to use png+json, with the JSON in the `array` format. If you use `hash` instead, the JSON cannot be imported.

[^1]: Technically, there are a few, but they're either GPL, shit[^2], or both. PNGs mixed with `.json` files remain superior by a margin so large it's hardly worth mentioning.
[^2]: The [biggest project](https://github.com/Laguna1989/aselib) of the projects I've been able to find lacks basic features that mean what you see in aseperite differ from what you'd see when rendered. This makes the library unusable.
