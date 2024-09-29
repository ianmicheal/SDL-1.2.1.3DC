
## Simple Transparency

Most special effects in OpenGL rely on some type of blending. Blending is used to combine the color of a pixel about to be drawn with the pixel already on the screen. The combination method is based on the alpha value of the colors and/or the blending function in use.
![Screenshot of SDL-DREAMHAL](https://github.com/ianmicheal/SDL-dreamhal--GLDC/blob/main/08.png)
### Key Points:
- Alpha is a 4th color component, usually specified at the end.
- Use `GL_RGBA` instead of `GL_RGB` to specify alpha.
- Use `glColor4f()` instead of `glColor3f()` to include alpha.
- Alpha values range from 0.0 (completely transparent) to 1.0 (totally opaque).

## The Blending Equation

For those interested in the mathematics behind blending:

```
(Rs Sr + Rd Dr, Gs Sg + Gd Dg, Bs Sb + Bd Db, As Sa + Ad Da)
```

Where:
- s and d subscripts specify the source and destination pixels
- S and D components are the blend factors

Common values:
- S: (As, As, As, As) (source alpha)
- D: (1, 1, 1, 1) - (As, As, As, As) (one minus src alpha)

This yields:

```
(Rs As + Rd (1 - As), Gs As + Gd (1 - As), Bs As + Bd (1 - As), As As + Ad (1 - As))
```

This equation produces transparent/translucent effects.

## Implementing Blending in OpenGL

1. Enable blending
2. Set the blending equation
3. Turn off depth buffer writing when drawing transparent objects

**Note:** This method, while simple, isn't always the correct approach for complex scenes.

## Best Practices for Transparent Objects

As noted by Rui Martins:

1. Draw all transparent (alpha < 1.0) polygons after rendering the entire opaque scene.
2. Draw transparent polygons in reverse depth order (farthest first).
3. Sort transparent polygons by depth.
4. Draw transparent objects with the depth buffer enabled.

### Explanation:
Blending two polygons in different orders yields different results. For correct visual representation, light should pass through farther objects before reaching nearer ones, mimicking reality.

## Texture Mapping and Blending

When using texture mapping with blending, the color specification works as follows:

- In modulated texture mode, each pixel that is texture mapped is multiplied by the current color.
- Example: If the color to be drawn is (0.5, 0.6, 0.4), and we multiply it by the texture color, we get (0.5, 0.6, 0.4, 0.2) (alpha is assumed to be 1.0 if not specified).

This simple multiplication allows for easy integration of textures with blending effects.

## Important Notes on Blending Implementation

1. **Artifact Prevention (11/13/99)**: 
   - Using alpha values for source and destination blending can cause artifacts (e.g., darker back faces, screwy object appearance).
   - The blending method has been modified to improve visual appearance, especially with lighting enabled.
   - While this may not be the mathematically "correct" way to blend with alpha values, it produces more visually appealing results.

2. **Depth Testing (Update)**: 
   - Due to issues with `glDepthMask()` on some video cards, the code has been reverted to use `glEnable` and `glDisable` for depth testing.

3. **Alpha from Texture Map**:
   - Alpha values for transparency can be read directly from a texture map.
   - To implement this:
     1. Ensure your image includes an alpha channel.
     2. Use `GL_RGBA` as the color format in calls to `glTexImage2D()`.

## Conclusion

Blending in OpenGL is a powerful technique that, while simple in concept, requires careful implementation for best results. By understanding the blending equation, properly handling transparent objects, and correctly integrating with texture mapping, you can achieve sophisticated visual effects in your OpenGL applications.

---

This README provides a comprehensive overview of blending in OpenGL, suitable for both beginners and those interested in the underlying mathematics and best practices.

