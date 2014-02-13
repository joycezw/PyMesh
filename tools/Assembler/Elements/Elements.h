#pragma once

#include <tr1/memory>

#include <Core/EigenTypedef.h>
#include <Mesh.h>

class Elements {
    public:
        typedef std::tr1::shared_ptr<Elements> Ptr;

    public:
        // Factories
        static Ptr adapt(Mesh::Ptr mesh);
        static Ptr adapt_boundary(Mesh::Ptr mesh);

    public:
        virtual size_t getDim() const=0;

        // Nodes
        virtual size_t getNbrNodes() const=0;
        virtual VectorF getNodes() const=0;
        virtual VectorF getNode(size_t vi) const=0;

        // Elements
        virtual size_t getNbrElements() const=0;
        virtual size_t getNodePerElement() const=0;
        virtual VectorI getElements() const=0;
        virtual VectorI getElement(size_t ei) const=0;
        virtual Float getElementVolume(size_t ei) const=0;
        virtual VectorF getElementCenter(size_t ei) const=0;
};