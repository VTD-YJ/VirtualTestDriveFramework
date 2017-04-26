//
// Created by geislerd on 26.04.17.
//

#ifndef ADTF_IO_IMAGEWRITER_H
#define ADTF_IO_IMAGEWRITER_H

#include <adtf/salbox/Image.h>
#include <io/MemoryWriter.h>
#include <utils/Image.h>
#include <saliency/Saliency.h>
#include <adtf/io/ConvertImage.h>

namespace saliency_sandbox {
    namespace adtf {

        template<uint32_t _width, uint32_t _height, typename _type>
        class ImageWriter :
                public saliency_sandbox::io::MemoryWriter<saliency_sandbox::utils::_Matrix<_width,_height,_type>,salbox::Image<_type>>,
                protected saliency_sandbox::adtf::ConvertImage<_type> {
        public:
            ImageWriter() : MemoryWriter(_width,_height) { };

            void cvt(Input *in, Output *out) override {
                this->convert(in,out);
            };
        };

        template<uint32_t _width, uint32_t _height>
        class GrayscaleImageWriter : public ImageWriter<_width,_height,uint8_t> { };

        template<uint32_t _width, uint32_t _height>
        class RGBImageWriter : public ImageWriter<_width,_height,uint8_t[3]> { };

        template<uint32_t _width, uint32_t _height>
        class SaliencyMapWriter : public ImageWriter<_width,_height,float> { };
    }
}
#endif //ADTF_IO_IMAGEWRITER_H
