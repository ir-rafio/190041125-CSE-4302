#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
    string name; // For task 3
public:

    Furniture(double p,double d,Material m):price(0),discount(0),madeof(Material::Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setDiscountPercentage(double val) // New function added
    {
        if(val<=100)
            discount=price*val/100;
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    void setName(string str) // New function added
    {
        name=str;
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    virtual void productDetails()=0;
    double getDiscountedPrice() const // New function added
    {
        return price-discount;
    }
};



enum class BedSize{Single, SemiDouble, Double};

class Bed:public Furniture
{
private:
    BedSize type;
public:
    Bed(double p,double d,Material m, BedSize bsize): Furniture(p,d,m), type(bsize)
    {}

    void productDetails()
    {
        for(int i=0; i<48; i++) cout << "-"; cout << endl;
        cout << "Product Name: "; name[0]? cout << name: cout << "Bed"; cout << endl; // For task 3
        cout << "Regular Price: " << price << endl;
        cout << "Discounted Price: " << price-discount << endl;
        cout << "Material: " << getMadeof() << endl;
        cout << "Bed Size: ";
        switch(type)
        {
        case BedSize::Single:
            cout << "Single\n";
            break;
        case BedSize::SemiDouble:
            cout << "SemiDouble\n";
            break;
        case BedSize::Double:
            cout << "Double\n";
        }
        for(int i=0; i<48; i++) cout << "#"; cout << endl;
    }
};

enum class SofaSize{One=1, Two, Three, Four, Five};

class Sofa:public Furniture
{
private:
    SofaSize seat;
public:
    Sofa(double p,double d,Material m, SofaSize num): Furniture(p,d,m), seat(num)
    {}

    void productDetails()
    {
        for(int i=0; i<48; i++) cout << "-"; cout << endl;
        cout << "Product Name: "; name[0]? cout << name: cout << "Sofa"; cout << endl; // For task 3
        cout << "Regular Price: " << price << endl;
        cout << "Discounted Price: " << price-discount << endl;
        cout << "Material: " << getMadeof() << endl;
        cout << "Number of Seats: ";
        switch(seat)
        {
        //case 1:
        case SofaSize::One:
            cout << "One\n";
            break;
        case SofaSize::Two:
            cout << "Two\n";
            break;
        case SofaSize::Three:
            cout << "Three\n";
            break;
        case SofaSize::Four:
            cout << "Four\n";
            break;
        case SofaSize::Five:
            cout << "Five\n";
        }
        for(int i=0; i<48; i++) cout << "#"; cout << endl;
    }

    /*Furniture *f;
    void a()
    {
        f = new Bed();
    }

    ~Sofa
    {
        delete f;
    }*/
};

enum class AlmirahSize{Two=2, Three, Four};

class Almirah:public Furniture
{
private:
    AlmirahSize door;
public:
    Almirah(double p,double d,Material m, AlmirahSize num): Furniture(p,d,m), door(num)
    {}

    void productDetails()
    {
        for(int i=0; i<48; i++) cout << "-"; cout << endl;
        cout << "Product Name: "; name[0]? cout << name: cout << "Almirah"; cout << endl; // For task 3
        cout << "Regular Price: " << price << endl;
        cout << "Discounted Price: " << price-discount << endl;
        cout << "Material: " << getMadeof() << endl;
        cout << "Number of Doors: ";
        switch(door)
        {
        case AlmirahSize::Two:
            cout << "Two\n";
            break;
        case AlmirahSize::Three:
            cout << "Three\n";
            break;
        case AlmirahSize::Four:
            cout << "Four\n";
        }
        for(int i=0; i<48; i++) cout << "#"; cout << endl;
    }
};

/**task 4
sort_furniture_discount will sort the array in descending order based on their discount price.
You may need to add some member functions
**/

void sort_furniture_discount(Furniture *furnitures[],int no_of_furnitures)
{
    for(int i=0; i<no_of_furnitures-1; i++) for(int j=i+1; j>0 && furnitures[j]->getDiscountedPrice()>furnitures[j-1]->getDiscountedPrice(); j--) swap(furnitures[j], furnitures[j-1]);
}


int main()
{
    Furniture* f_list[100];

    /**
        task 1
        So that following lines can be executed without error
    */
    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,234,Material::Steel,SofaSize::Five);
    f_list[2] = new Almirah(13000,345,Material::Wood,AlmirahSize::Two); // This line was modified
    f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);

    /**task 1 ends here*/

    /**
        task 2
        So that following lines can be executed without error

        task 3 (Modify productDetails)
    */
    f_list[2]->setDiscountPercentage(30); // This line was modified
    f_list[0]->setName("Bahari Bed"); // For task 3
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }

    /**task 2 ends here*/
    /**task 3 ends here*/

    /**task 4
    So that following lines can be executed without error
    */
    sort_furniture_discount(f_list,4);
    cout << "\n\n";
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }
    /**task 4 ends here*/

    for(int i=0; i<4; i++) delete f_list[i];
    return 0;
}
