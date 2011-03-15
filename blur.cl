 const sampler_t samp = CLK_ADDRESS_CLAMP_TO_EDGE |
                           CLK_FILTER_LINEAR;

    __kernel void hgaussian(__read_only image2d_t srcImage,
                            __write_only image2d_t dstImage,
                            __global __read_only float *weights,
                            __global __read_only float *offsets,
                            const int numWeights)
    {
        int2 pos = (int2)(get_global_id(0), get_global_id(1));
        float2 srcpos = (float2)(get_global_id(0), get_global_id(1));
        int index;
        float4 pixel = (float4)(0, 0, 0, 0);
        for (index = 0; index < numWeights; ++index) {
            pixel += read_imagef(srcImage, samp,
                                 srcpos + (float2)(offsets[index], 0.0f)) *
                     weights[index];
        }
        write_imagef(dstImage, pos, clamp(pixel, 0.0f, 1.0f));
    }

    __kernel void vgaussian(__read_only image2d_t srcImage,
                            __write_only image2d_t dstImage,
                            __global __read_only float *weights,
                            __global __read_only float *offsets,
                            const int numWeights)
    {
        int2 pos = (int2)(get_global_id(0), get_global_id(1));
        float2 srcpos = (float2)(get_global_id(0), get_global_id(1));
        int index;
        float4 pixel = (float4)(0, 0, 0, 0);
        for (index = 0; index < numWeights; ++index) {
            pixel += read_imagef(srcImage, samp,
                                 srcpos + (float2)(0.0f, offsets[index])) *
                     weights[index];
        }
        write_imagef(dstImage, pos, clamp(pixel, 0.0f, 1.0f));
    }