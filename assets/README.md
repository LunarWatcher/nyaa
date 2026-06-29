# Assets

This folder contains the various assets, including the raw `.aseprite` files. 

This folder contains a mix of exported and non-exported files. Only the `.json` and `.png` files are exported during the build, as `.aseprite` is a proprietary format without any C/C++-based parsers[^1], so it has no value at runtime.

## Export requirements

The exports are assumed to use png+json, with the JSON in the `array` format. If you use `hash` instead, the JSON cannot be imported.

Command (TODO: script):
```
export name=creatures
aseprite --list-slices --sheet ${name}.png --data ${name}.json --format json-array -b ${name}.aseprite
```

## Future plans

Right now, everything is pre-baked into spritesheets. This does somewhat limit the game's ability to use the full set of aseprite features, and definitely complicates anything involving multiple people working on different sprites if they happen to  be in the same spritesheet.

In the future, this will likely be split into one aseprite file per asset, that's then packed into a single bitmap on the GPU. Even with the same setup as today, this would allow multiple full spritesheets to be packed into the same GPU bitmap, provided the sheets are small enough to fit in whatever the largest bitmap size is on any given GPU. This means better GPU resource utilization.

## Third party assets

The only third party asset currently in use is `fonts/dejavu.ttf`. The licenses for these assets are in `Asset-licenses.md`

[^1]: Technically, there are a few, but they're either GPL, shit[^2], or both. PNGs mixed with `.json` files remain superior by a margin so large it's hardly worth mentioning.
[^2]: The [biggest project](https://github.com/Laguna1989/aselib) of the projects I've been able to find lacks basic features that mean what you see in aseperite differ from what you'd see when rendered. This makes the library unusable.
