# minishell
Minishell group project for 42 school

executor klasoru KISMI SIMDIYE KADARKI SUREC :
main fonksiyonunda sirayla obtain_the_path_list ve obtain_exact_path fonksiyonlari cagirilacak. Henuz exact pathlerin x_ok vb vb izinlerine bakilmadi. bunlar child process asamasinda yapilacak. obtain exact path, tam yol verildiyse oldugu gibi ilgili stringin icine verilen yolu yazar, builtin verildiyse onu null olarak listesine ekler, relative komutlar verildiyse (ls, cat vb vb. ) bunlarin yollarini bulur. ve listenin icine o sekilde ekler.


commands adindaki bir string listesinin icinde her komutun ilk argumani yer almali.