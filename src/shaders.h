/* This file was autogenerated. */


const char*
font_vs_src =
"#version 120\n"
"attribute vec4 coord;"
"varying vec2 tex_coord;"
"void main(){"
"tex_coord=coord.zw;"
"gl_Position=vec4(coord.xy,0,1);"
"}";


const char*
bg_vs_src =
"#version 120\n"
"attribute vec2 pos;"
"uniform vec2 mv;"
"void main(){"
"gl_Position=vec4(pos+mv,0,1);"
"}";


const char*
image_rgb_vs_src =
"#version 120\n"
"attribute vec4 coord;"
"varying vec2 tex_coord;"
"void main(){"
"tex_coord=coord.zw;"
"gl_Position=vec4(coord.xy,0,1);"
"}";


const char*
line_vs_src =
"#version 120\n"
"attribute vec2 pos;"
"void main(){"
"gl_Position=vec4(pos,0,1);"
"}";


const char*
font_fs_src =
"#version 120\n"
"uniform vec3 clr;"
"uniform vec4 bclr;"
"uniform sampler2D tex;"
"varying vec2 tex_coord;"
"void main(){"
"vec3 c=texture2D(tex,tex_coord).rgb;"
"gl_FragData[0]=vec4(mix(bclr.r,clr.r,c.r),"
"mix(bclr.g,clr.g,c.g),"
"mix(bclr.b,clr.b,c.b),"
"bclr.a+length(c));"
"}";


const char*
bg_fs_src =
"#version 120\n"
"uniform vec4 clr;"
"void main(){"
"gl_FragData[0]=clr;"
"}";


const char*
image_tint_rgb_fs_src =
"#version 120\n"
"uniform sampler2D tex;"
"uniform vec3 tint;"
"varying vec2 tex_coord;"
"void main(){"
"gl_FragData[0]=texture2D(tex,tex_coord)*vec4(tint,1.0);"
"}";


const char*
image_rgb_fs_src =
"#version 120\n"
"uniform sampler2D tex;"
"varying vec2 tex_coord;"
"void main(){"
"gl_FragData[0]=texture2D(tex,tex_coord);"
"}";


const char*
line_fs_src =
"#version 120\n"
"uniform vec3 clr;"
"void main(){"
"gl_FragData[0]=vec4(clr,1);"
"}";
