#include <time.h>
template <typename T> class DimValue {
private:
	T* value;
	unsigned long long l = 0;
	unsigned long long rl = 0;
	DimValue(T* value, unsigned long long l) {
		if (rl > 0) delete this->value;
		this->value = value;
		this->l = l;
		this->rl = l;
	}
	unsigned long long rand() {
		std::srand(time(0));
		unsigned long long a = std::rand();
		return a;
	}
	static const unsigned long long maxMemory = 10;
public:
	DimValue() {
		if (rl > 0) delete[] value;
		this->l = 0;
		this->rl = rand() % maxMemory;
		value = new T[rl];
	}
	DimValue(unsigned long long l) {
		if (rl > 0) delete[] value;
		this->value = new T[l];
		this->l = 0;
		this->rl = l;
	}
	DimValue(const DimValue<T>& dv) {
		if (rl > 0) delete[] value;
		this->value = new T[dv.l];
		this->l = dv.l;
		this->rl = dv.l;
		for (unsigned long long i = 0; i < dv.l; i++) {
			this->value[i] = dv.value[i];
		}
	}

	~DimValue() {
		if (rl > 0) delete[] value;
		this->l = 0;
		this->rl = 0;
	}
	DimValue& operator = (const DimValue& a) {
		if (rl > 0) delete[] value;
		value = new T[a.l];
		this->l = a.l;
		this->rl = a.l;
		for (unsigned long long i = 0; i < a.l; i++) {
			this->value[i] = a.value[i];
		}
		return *this;
	}
	bool operator == (const DimValue& a) {
		if (this->l == a.l && this->rl == a.rl) {
			for (unsigned long long i = 0; i < a.l; i++) {
				if (this->value[i] != a.value[i]) return false;
			}
			return true;
		}
		else return false;
	}
	bool operator != (const DimValue& a){
		return !*this == a
	}
	bool operator < (const DimValue& a) {
		if (this->l == a.l) {
			for (unsigned long long i = 0; i < a.l; i++) {
				if (this->value[i] < a.value[i]) return true;
				if (this->value[i] > a.value[i]) return false;
			}
		}
		else if (this->l < a.l) return true;
		return false;
	}

	T& operator [](unsigned long long id) {
		if (id < l) {
			return value[id];
		}
		T* ret = new T(0);
		return *ret;
	}
	T& operator [](unsigned long long id) const {
		if (id < l) {
			return value[id];
		}
		else {
			T* ret = new T(0);
			return *ret;
		}
	}

	void add(T data) {
		if (l < rl) {
			value[l++] = data;
		}
		else {
			rl += (rand() % maxMemory) +1;
			T* tmp = new T[rl];
			for (unsigned long long i = 0; i < l; i++) {
				tmp[i] = value[i];
			}
			tmp[l] = data;
			l++;
			delete[] value;
			value = new T[rl];
			for (unsigned long long i = 0; i < l; i++) {
				value[i] = tmp[i];
			}
			delete[] tmp;
		}
	}

	void add(const DimValue<T>& a) {
		addToBack(a);
	}

	void addToBack(T data) {
		this->add(data);
	}

	void addToBack(const DimValue<T>& a) {
		if (rl > this->l + a.l) {
			for (unsigned long long i = 0; i < a.l; i++) {
				this->value[i + l] = a.value[i];
			}
			this->l = this->l + a.l;
		}
		else {
			rl += this->l + a.l;
			T* tmp = new T[rl];
			for (unsigned long long i = 0; i < this->l; i++) {
				tmp[i] = value[i];
			}
			for (unsigned long long i = 0; i < a.l; i++) {
				tmp[i + this->l] = a[i];
			}
			l += a.l;
			delete[] value;
			value = new T[rl];
			for (unsigned long long i = 0; i < l; i++) {
				value[i] = tmp[i];
			}
			delete[] tmp;
		}
	}

	void addToStart(T data) {
		if (l < rl) {
			for (unsigned long long i = l; i != 0;i--) {
				value[i] = value[i - 1];
			}
			value[0] = data;
			l++;
		}
		else {
			rl += (rand() % maxMemory) + 1;
			T* tmp = new T[rl];
			tmp[0] = data;
			for (unsigned long long i = 0; i < l; i++) {
				tmp[i + 1] = value[i];
			}
			l++;
			delete[] value;
			value = new T[rl];
			for (unsigned long long i = 0; i < l; i++) {
				value[i] = tmp[i];
			}
			delete[] tmp;
		}
	}

	void addToStart(DimValue<T>& a) {
		if (rl > this->l + a.l) {
			for (unsigned long long i = l + a.l - 1; i < -1; i--) {
				this->value[i] = this->value[i - a.l];
			}
			for (unsigned long long i = 0; i < a.l; i++) {
				this->value[i] = a.value[i];
			}
			this->l = this->l + a.l;
		}
		else {
			this->rl = this->l + a.l;
			T* tmp = new T[this->rl];
			for (unsigned long long i = 0; i < a.l; i++) {
				tmp[i] = a.value[i];
			}
			for (unsigned long long i = a.l; i < rl; i++) {
				tmp[i] = this->value[i - a.l];
			}
			l +=a.l;
			delete[] this->value;
			value = new T[rl];
			for (unsigned long long i = 0; i < l; i++) {
				value[i] = tmp[i];
			}
			delete[] tmp;
		}
	}
	
	void remove(unsigned long long id) {
		if (id < this->l) {
			for (unsigned long long i = id; i < this->l-1; i++) {
				this->value[i] = this->value[i + 1];
			}
			l--;
		}
	}

	void remove(unsigned long long start, unsigned long long end) {
		if (start == end) remove(start);
		else if (start < end && start < l && end < l) {
			unsigned long long l_0 = end - start;
			for (unsigned long long i = start; i < l - l_0; i++) {
				this->value[i] = this->value[i + l_0];
			}
			this->l = this->l - l_0;
		}
	}

	void removeFirst() {
		if (l > 1) {
			for (unsigned long long i = 0; i < l - 1; i++) {
				value[i] = value[i + 1];
			}
			l--;
		}
	}

	void removeBack() {
			l--;
	}

	void removeFirst(T data) {
		if (l > 1) {
			unsigned long long index = -1;
			for (unsigned long long i = 0; i < l-1; i++) {
				if (this->value[i] != data) break;
				index = i;
			}
			if (index < -1) {
				remove(0, index);
			}
		}
	}

	void setData(unsigned long long id, T& data) {
		if (id < l) this->value[id] = data;
	}

	void clear() {
		l = 0;
	}

	void set(DimValue<T>& data) {
		if (data.l > rl) {
			if (rl > 0) delete[] value;
			value =new T[data.rl];
			rl = data.rl;
			l = data.l;
			for (unsigned long long i = 0; i < l; i++) {
				value[i] = data.value[i];
			}
		}
		else {
			l = data.l;
			for (unsigned long long i = 0; i < l; i++) {
				value[i] = data.value[i];
			}
		}
	}

	void set(const DimValue<T>& data) {
		if (data.l > rl) {
			if (rl > 0) delete[] value;
			value = new T[data.rl];
			rl = data.rl;
			l = data.l;
			for (unsigned long long i = 0; i < l; i++) {
				value[i] = data.value[i];
			}
		}
		else {
			l = data.l;
			for (unsigned long long i = 0; i < l; i++) {
				value[i] = data.value[i];
			}
		}
	}

	void set(DimValue<T>* data) {
		if (data->l > rl) {
			if (rl > 0) delete[] value;
			value = new T[data->rl];
			rl = data->rl;
			l = data->l;
			for (unsigned long long i = 0; i < l; i++) {
				value[i] = data.value[i];
			}
		}
		else {
			l = data->l;
			for (unsigned long long i = 0; i < l; i++) {
				value[i] = data->value[i];
			}
		}
	}

	bool clearMemory() {
		if (l < rl){
			T* tmp = new T[l];
			for (unsigned long long i = 0; i < l; i++) {
				tmp[i] = this->value[i];
			}
			delete[] value;
			rl = l;
			value = tmp;
		}
		else return false;
	}

	unsigned long long freeSize() {
		return rl - l;
	}

	unsigned long long useSize() {
		return l;
	}

	unsigned long long realSize() {
		return rl;
	}

	unsigned long long size() const {
		return l;
	}

	T get(unsigned long long id) {
		if (id < l) {
			return value[id];
		}
		else return 0;
	}

	unsigned long long find(T data) {
		for (unsigned long long i = 0; i < l; i++) {
			if (this->value[i] == data) return i;
		}
		return -1;
	}

	T* subArray(unsigned long long startIndex) {
		if (startIndex < l) {
			T* tmp = new T[l - startIndex];
			for (unsigned long long i = startIndex; i < l; i++) {
				tmp[i - startIndex] = value[i];
			}
			return tmp;
		}
		return new T[0];
	}

	T* subArray(unsigned long long startIndex, unsigned long long endIndex) {
		if (startIndex <= endIndex && startIndex < l && endIndex < l) {
			unsigned long long l = endIndex - startIndex+1;
			T* tmp = new T[l];
			for (unsigned long long i = startIndex; i <= endIndex; i++) {
				tmp[i - startIndex] = value[i];
			}
			return tmp;
		}
		return new T[0];
	}

	DimValue* subValue(unsigned long long startIndex) {
		if (startIndex < l) {
			T* tmp = subArray(startIndex);
			DimValue* ret = new DimValue(tmp, l - startIndex);
			return ret;
		}
		else return new DimValue();
	}

	DimValue<T>* subValue(unsigned long long startIndex, unsigned long long l) {
		if (startIndex < this->l) {
			if (this->l < startIndex + l) {
				return subValue(startIndex);
			}
			else {
				T* tmp = subArray(startIndex, startIndex + l-1);
				DimValue<T>* ret = new DimValue<T>(tmp, l);
				return ret;
			}
		}
		return new DimValue();
	}

	void revers() {
		if (l > 1) {
			T* tmp = new T[rl];
			for (unsigned long long i = 0; i < l; i++) {
				tmp[l - i - 1] = value[i];
			}
			delete[] value;
			value = tmp;
		}
	}

	void resize(unsigned long long lenght) {
		if (rl < lenght && lenght > 0) {
			if (l > 0) {
				T* tmp = new T[lenght];
				for (unsigned long long i = 0; i < lenght && i < this->l; i++) {
					tmp[i] = value[i];
				}
				delete[] value;
				value = tmp;
			}
			else {
				delete[] value;
				value = new T[lenght];
				rl = lenght;
			}
		}
	}

	static void setMaxMemory(unsigned long long max) {
		DimValue::maxMemory = max;
	}
};