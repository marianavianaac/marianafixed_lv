#ifndef DATA_STRUCTURES_FLV
#define DATA_STRUCTURES_FLV
#include <algorithm>

namespace data_structures {
template <typename T>
class FLV {
public:
	FLV(int size):
		contents{new T[size]},
		size_{size}
	{}
	~FLV()
	{
		delete[] contents;
	}
	
	FLV(FLV const& other):
		contents{ new T[other.size_] },
		size_{other.size_ }
	{
		for (auto i = 0; i < size_; ++i) {
			contents[i] = other[i];
		}
	}

	FLV(FLV&& other) :
		contents{ other.contents },
		size_{ other.size_ }
	{
		other.contents = nullptr;
	}
	
	FLV& operator= (FLV const& other)
	{
		auto auxi = other;
		this->swap(auxi);
		return *this;
			
	}

	FLV& operator= (FLV&& other)
	{
		auto auxi = std::move(other);
		this->swap(auxi);
		return *this;

	}

	T& operator[](int i)
	{
		return contents[i];
	}

	T const& operator[](int i) const
	{
		return contents[i];
	}

	void swap(FLV& other)
	{
		using std::swap;
		
		swap(contents, other.contents);
		swap(size_, other.size_);
	}

private:
	T* contents;
	int size_;
};
}




#endif // !DATA_STRUCTURES_FLV
