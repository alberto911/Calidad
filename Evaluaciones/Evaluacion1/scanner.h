#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Scanner {
	vector<int> ports;
public:
    static int count;
	Scanner() {
		// Obtener puertos abiertos y guardar en archivo
		system("netstat -lntu | awk '$4 ~ /:/ {print $4}' | sed -e 's/.*://' > ports.txt");
		string line;
		ifstream myfile ("ports.txt");
		if (myfile.is_open()) {
			while(getline(myfile, line))
				ports.push_back(atoi(line.c_str())); // Insertar cada puerto en el vector
		}
	}

	vector<int> getOpenPorts() {
		return ports;
	}

	bool testPort(int p) {
		// Buscar el puerto en el vector
		for (vector<int>::iterator it = ports.begin(); it != ports.end(); ++it) {
			if (*it == p)
				return true;
		}
		return false;
	}

	void* operator new(size_t size) {
		++count;
		void* p = ::new Scanner();
		return p;
	}

	void operator delete(void* p) {
		--count;
		free(p);
	}
};

int Scanner::count = 0;
