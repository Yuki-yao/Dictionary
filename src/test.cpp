#include <cstdio>
int main(){
	#ifdef __APPLE__
	printf("Hello I'm using Apple Product");
	#endif
	#ifdef _WIN32
	printf("Hello I'm using Windows");
	#endif
	return 0; 
}