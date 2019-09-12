//
// Created by wmurphy on 9/12/2019.
//

#ifndef DATASTRCTURES_ALGORITHMS_SHAPEINTERFACE_H
#define DATASTRCTURES_ALGORITHMS_SHAPEINTERFACE_H


namespace WMurphy {

    // interface class for defining methods
    class ShapeInterface {
    private:
        int dimension;
        int num_faces;
        int width{0};
        int height{0};
        int depth{0};

    public:
        virtual int getArea() = 0;
        virtual int getVolume() = 0;
        virtual void setNumDimensions(int);
    };

}

#endif //DATASTRCTURES_ALGORITHMS_SHAPEINTERFACE_H
