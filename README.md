[한국어](README.ko.md)

# miniRT

A ray tracer written in C using MiniLibX. Renders 3D scenes defined in `.rt` files. 42 Seoul team project — 2 contributors.

<!-- Add a rendered screenshot here -->

## Features

- **Objects** — sphere, plane, cylinder
- **Lighting** — ambient + diffuse lighting with shadow casting
- **Camera** — configurable position, direction, and field of view
- **Scene files** — plain-text `.rt` format defining objects, lights, and camera

```
A  0.1  255,255,255          # ambient
C  0,0,200  0,0,-1  70       # camera (position, direction, FOV)
L  60,60,120  0.8  255,255,255
sp 0,0,0  20  255,0,0        # sphere (center, diameter, color)
pl 0,-20,0  0,1,0  200,200,200
cy 0,20,0  0,1,0  10  30  0,0,255
```

## Build & Run

```bash
make
./miniRT example.rt
```

Requires Linux + MiniLibX.

## References

Ray tracing fundamentals from [Ray Tracing in One Weekend (Korean)](https://github.com/sejinpark12/RayTracing_in_One_Weekend_Kor)

## Team

| | GitHub | Role |
|---|---|---|
| **sypyeon** | [@sypyeon](https://github.com/sypyeon) | ray-object intersection · Phong lighting · viewport |
| **jaehylee** | [@jaehylee](https://github.com/jaehylee) | `.rt` scene file parsing · union-based object structs |
