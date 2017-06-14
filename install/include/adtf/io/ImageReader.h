//
// Created by geislerd on 26.04.17.
//

#ifndef ADTF_IO_IMAGEREADER_H
#define ADTF_IO_IMAGEREADER_H

#include <adtf/salbox/Image.h>
#include <io/MemoryReader.h>
#include <utils/Image.h>
#include <saliency/Saliency.h>
#include <adtf/io/ConvertImage.h>

namespace saliency_sandbox {
    namespace adtf {

        template<uint32_t _width, uint32_t _height, typename _type>
        class ImageReader :
                public saliency_sandbox::io::MemoryReader<salbox::Image<_type>,saliency_sandbox::utils::_Matrix<_width,_height,_type>>,
                public saliency_sandbox::adtf::ConvertImage<_type> {
        public:
            void cvt(salbox::Image<_type> *in, saliency_sandbox::utils::_Matrix<_width,_height,_type> *out) override {
                this->convert(in,out);
            };
        };

        template<uint32_t _width, uint32_t _height>
        class GrayscaleImageReader : public ImageReader<_width,_height,uchar> { };

        template<uint32_t _width, uint32_t _height>
        class RGBImageReader : public ImageReader<_width,_height,cv::Vec3b> { };

        template<uint32_t _width, uint32_t _height>
        class SaliencyMapReader : public ImageReader<_width,_height,float> { };
    }
}
#endif //ADTF_IO_IMAGEREADER_H
