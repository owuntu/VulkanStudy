set VulkanSDKDir=D:\personalWS\VulkanSDK\1.3.216.0\
%VulkanSDKDir%Bin\glslc.exe -fshader-stage=vert .\glsl\vertexShader.glsl -o .\spv\vertexShader.spv
%VulkanSDKDir%Bin\glslc.exe -fshader-stage=frag .\glsl\fragmentShader.glsl -o .\spv\fragmentShader.spv

