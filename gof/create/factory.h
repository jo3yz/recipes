#ifndef GOF_FACTORY_H
#define GOF_FACTORY_H


namespace gof
{
    class ProductBase
    {
    public:
        typedef std::shared_ptr<ProductBase> Ptr;
        virtual void Print()  = 0;
    };

    class ProductA : public ProductBase
    {
    public:
        typedef std::shared_ptr<ProductBase> Ptr;
        void Print() override;
    };

    class ProductB : public ProductBase
    {
    public:
        typedef std::shared_ptr<ProductBase> Ptr;
        void Print() override;
    };

    // factory method
    template <typename T>
    class Factory
    {
    public:
        static typename T::Ptr CreateProduct()
        {
            return std::make_shared<T>();
        }
    };

    static void FactoryTest()
    {
        ProductBase::Ptr pa = Factory<ProductA>::CreateProduct();
        pa->Print();
        ProductBase::Ptr pb = Factory<ProductB>::CreateProduct();
        pb->Print();
    }
}


#endif //GOF_FACTORY_H
