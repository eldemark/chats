
"""
const char* vertexShaderSource = R"glsl(
#version 330 core
layout (location = 0) in vec3 aPos;

void main()
{
    gl_Position = vec4(aPos, 1.0);
}
)glsl";
"""

# script: glsl_to_header.py

import sys

def convert_glsl_to_header(input_file, output_file):
    with open(input_file, 'r') as file:
        lines = file.readlines()

    with open(output_file, 'w') as file:
        file.write('#ifndef VERTEX_SHADER_H\n')
        file.write('#define VERTEX_SHADER_H\n\n')
        file.write('const char* vertexShaderSource = R"glsl(\n')
        for line in lines:
            file.write(line)
        file.write(')glsl";\n\n')
        file.write('#endif // VERTEX_SHADER_H\n')

if __name__ == "__main__":
    input_file = sys.argv[1]
    output_file = sys.argv[2]
    convert_glsl_to_header(input_file, output_file)


"""
# make file
vertex.h: vertex.glsl
    python glsl_to_header.py vertex.glsl vertex.h
"""

"""
# In source
#include "vertex.h"

// Now you can use vertexShaderSource as a string containing your GLSL code
"""
