precision highp float; // this will make the default precision high

uniform sampler2D   tex0;
varying vec2        texcoord0;

void main()
{
    vec4 texColor = texture2D(tex0, texcoord0);  
    gl_FragColor = vec4(1.0-texColor.r, 1.0-texColor.g, 1.0-texColor.b, texColor.a);
}