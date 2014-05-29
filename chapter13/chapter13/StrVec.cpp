#include "StrVec.h"
#include <mysql++.h>
#include <sql_types.h>
//#include <string>
using namespace std;

void StrVec::push_back(const string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e-b);
	return { data, uninitialized_copy(b, e, data) };//�Է���ֵ�б��ʼ��
}
void StrVec::free()
{
	if (elements)
	{
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}
StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec::~StrVec()
{
	free();
}
StrVec& StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}
int main()
{
	int i = 42;//��ֵ��ָ���ʽ�����������Ȼ���ڵĳ־ö���
	int &r = i;//��ֵ��ָ���ʽ���������Ͳ��ٴ��ڵ���ʱ����
	const int &r3 = i * 42;
	int &&rr2 = i * 42;
	cout << r << " " << r3 <<" "<< rr2 << endl;
	system("pause");
	return 0;
}