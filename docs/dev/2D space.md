# 2D space

The bulk of the game is a top-down game in a 3D-ish world. All rendering is 2D because 3D modeling is hard and I can't. 

"width" and "height" refer to the 2D width and height of the thing in question, even though they technically refer to the x and z axes in 3D space. 3D height is referred to as a z index outside the dungeon, and a floor level in the dungeon. This makes 3D height the Z axis, even though this is wrong[^1].

Because we're not rendering real 3D height, each z-level is whatever height makes sense to fit everything in it. 

[^1]: Technically it isn't, it's just a matter of what you label each axis as. However, I'm usex to y being height, and z being depth, and  because that corresponds with 2D graphs. z often becomes the height when switching from 2D to 3D, but that's just unnecessary axis meaning switching in my opinion. The switch here is necessary to avoid weird z->y translations for rendering, since all the rendering is in the 2D xz-plane, with the real y only being an internal data storage thing.
