#include <forward_list>

using namespace std;

const int maxColision = 3;
const float maxFillFactor = 0.5;

template<typename TK, typename TV>
class ChainHash{
private:    
    struct Entry{
		TK key;
		TV value;
		size_t hashcode;		
	} 
	forward_list<Entry> *array;
	int capacity;//tamanio del array
    int size;//cantidad de elementos totales

public:
    ChainHash(){
		// TODO: asignar un tamanio inicial al array
		capacity = 10; 
		array = new list<Entry>[capacity];
		size = 0;
	}

	void set(TK key, TV value){
		if(fillFactor() >= maxFillFactor) rehashing();
		size_t hashcode = getHashCode(key);
		int index = hashcode % capacity;
		//Completar para el caso cuando el set tiene que actualizar 
		array[index].push_front(Entry(key, value));
	}

	TV get(TK key){
        size_t hashcode = getHashCode(key);
        int index = hashcode % capacity;
        //Iteramos para buscar la key
    }

	void remove(TK key){

    }
    int bucket_count(){

    }

    int bucket_size(int index){

    }

    

	//TODO +1 en el parcial: implementar el operador corchete [ ], read/write

private:
	double fillFactor(){
		return size / (capacity * maxColision);
	}

	size_t getHashCode(TK key){
		std::hash<TK> ptr_hash;
		return ptr_hash(key);
	}

	void rehashing(){
        
    }
};