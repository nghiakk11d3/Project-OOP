#ifndef PRICE
#define PRICE

#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

// class Price
class Price
{
public:
	int priceProduct;
	int finallyPrice;
	char Discount[10];

	// Phương thức
	void setpriceProduct(int price)
	{
		this->priceProduct = price;
	}

	void setfinallyPrice(int price)
	{
		this->finallyPrice = price;
	}
};

#endif