#include <iostream>
#include <vector>
#include <memory>


class Sales_data {
public:
	Sales_data() = default;//Ĭ�Ϲ��캯��
	Sales_data(const Sales_data&);//���캯����ʼ�������ķ�static���ݳ�Ա����Ա��ʼ���ǰ��������г��ֵ�˳���ں�����ִ��֮ǰ���
	~Sales_data() = default;//���������ͷŶ���ʹ�õ���Դ�������ٷ������ķ�static���ݳ�Ա���������������ܲ������ʲ��ܱ����أ�
	//��Ա����˳���ǰ��ճ�ʼ�����������ٵ�
	Sales_data& operator=(const Sales_data &rhs);
private:
	std::string bookNo;
	int units_sold = 0;//C++11������....��ǰֻ����static const ���α������������ڲ���ʼ��
	double revenue = 0.0;
};


Sales_data::Sales_data(const Sales_data &orig):bookNo(orig.bookNo),
                                           units_sold(orig.units_sold),
										   revenue(orig.revenue)
{}
Sales_data& Sales_data::operator=(const Sales_data &rhs)
{
	bookNo = rhs.bookNo;
	units_sold = rhs.units_sold;
	revenue = rhs.revenue;
	return *this;
}