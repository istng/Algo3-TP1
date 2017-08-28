

void imprimirVector(std::vector<int> v){
    if(v.size() != 0){
        std::cout << "{ ";
        for (int i = 0; i < v.size()-1; ++i){
            std::cout << v[i] << ", ";
        }
        std::cout << v[v.size()-1] << " }" << std::endl;
    } else {
    	std::cout << "{ }" << std::endl;
    }
}


bool esta(std::vector<int> v, int a){
	bool res = false;
	for (int i = 0; i < v.size(); ++i){
		if (v[i] == a){
			res = true;
			break;
		}
	}
	return res;
}


int modulo(int a){
	int res = a;
	if (a < 0){res = -1*a;} 
	return res;
}

int signo(int a){
	int res = 1;
	if(a < 0){res = -1;}
	return res;
}