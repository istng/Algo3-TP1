

void imprimirVector(std::vector<int> v){
    if(v.size() != 0){
        std::cout << "{ ";
        for (int i = 0; i < v.size()-1; ++i){
            std::cout << v[i] << ", ";
        }
        std::cout << v[v.size()-1] << " }" << std::endl;
    }
}

bool esta(int a, std::vector<int> v){
	res = false;
	for (int i = 0; i < v.size(); ++i){
		if (v[i] == a){res = true;}
	}
	return res;
}