#include <iostream> 
#include <vector> 
#include <random>
#include <cstring> // for strcmp (string compare)

int main(int argc, char *argv[]){

	using namespace std;
	// declaring names
	vector<string> creature_size{
		"diminutive",	//bat
		"tiny",		//cat
		"small",	//halfling,
		"medium",	//human
		"large",	//horse
		"huge",		//ogre
	};

	vector<string> creature_base{
		"alligator",
		"alpaca",
		"ant",
		"antelope",
		"ape",
		"aphid",
		"armadillo",
		"baboon",
		"badger",
		"bald eagle",
		"bat",
		"bear",
		"beaver",
		"bee",
		"bird",
		"bison",
		"buffalo",
		"camel",
		"caribou",
		"cat",
		"caterpillar",
		"catfish",
		"cheetah",
		"chicken",
		"chimpanzee",
		"chipmunk",
		"cobra",
		"condor",
		"cow",
		"coyote",
		"crab",
		"crane",
		"cricket",
		"crocodile",
		"crow",
		"deer",
		"dog",
		"dove",
		"dragonfly",
		"duck",
		"eagle",
		"eel",
		"elephant",
		"emu",
		"falcon",
		"ferret",
		"flamingo",
		"flea",
		"fly",
		"fox",
		"frog",
		"goat",
		"gorilla",
		"grasshopper",
		"hamster",
		"hare",
		"hawk",
		"hippopotomus",
		"horse",
		"hummingbird",
		"iguana",
		"kangaroo",
		"ladybug",
		"leopard",
		"lion",
		"lizard",
		"llama",
		"lobster",
		"mongoose",
		"monitor lizard",
		"monkey",
		"moose",
		"mosquito",
		"moth",
		"mule",
		"octopus",
		"ostrich",
		"otter",
		"owl",
		"ox",
		"oyster",
		"panda",
		"parrot",
		"peacock",
		"pelican",
		"penguin",
		"perch",
		"pheasant",
		"pig",
		"pigeon",
		"porcupine",
		"rabbit",
		"racoon",
		"rat",
		"rattlesnake",
		"raven",
		"rooster",
		"sheep",
		"shrew",
		"skunk",
		"snail",
		"snake",
		"spider",
		"tiger",
		"walrus",
		"wolf",
		"zebra",
	};

	vector<string> creature_type_normal{
		"creature",
		"hybrid",
		"spirit",
		"monster",
	};

	vector<string> creature_type_extreme{
		"creature",
		"humanoid",
		"abomination",
		"hybrid",
		"spirit",
		"monster",
		"freak",
	};

	vector<string> creature_magic_use{
		"hunts with the use of",
		"finds a mate with the use of",
		"has a resistance to",
		"hides or runs away with the use of",
		"consumes (directly)",
		"foritifies it's soul with",
		"unthinkingly produces",
	};

	vector<string> creature_magic_type{
		"nothing particuarly magical",
		"fire",
		"cold",
		"wind energy",
		"electrical power",
		"psychic power",
		"necrotic magic",
		"vampirism",
		"telekenetic force",
		"magical strength",
		"magical speed",
		"mystical power",
		"shadow",
	};

	vector<string> creature_appendage_type{
		"set of horns",
		"tail",
		"set of claws",
		"pair of wings",
		"glorious mane",
		"glorious plumage",
	};

	vector<string> creature_skin_type{
		"thin transluscent material",
		"thick leather",
		"scales",
		"feathers",
		"fur",
	};

	//random engines
	random_device r;
	mt19937 eng(r());
	uniform_int_distribution<int> size(0, creature_size.size()-1 );
	uniform_int_distribution<int> animal(0, creature_base.size()-1 );
	uniform_int_distribution<int> type(0, creature_type_normal.size()-1 );
	uniform_int_distribution<int> type_extreme(0, creature_type_extreme.size()-1 );
	uniform_int_distribution<int> magic_use(0, creature_magic_use.size()-1 );
	uniform_int_distribution<int> magic(0, creature_magic_type.size()-1 );
	uniform_int_distribution<int> appendage(0, creature_appendage_type.size()-1 );
	uniform_int_distribution<int> skin(0, creature_skin_type.size()-1 );

	//the magic happens here!
	int count;
	char* option;
	if (argc == 3){
		count = atoi(argv[1]);
		option = argv[2];
	} else if (argc == 2) {
		if ((strcmp (argv[1] , "h")) == 0 || (strcmp (argv[1] , "--help")) == 0){
			cout 	<< "h or --help for this menu," << endl
				<< "r or --random for a completely random creature," << endl
				<< "hy or --hybrid for hybrid creature" << endl 
				<< "--horth for a creature with the rules of Horth" << endl
				<< "--yemit for a creature with the rules of Yemit"<< endl
				<< "--ro for a creature with the rules of Ro" << endl
				<< "a or --all for a complete list" << endl
				<< endl;
		}
       	} else {
		cout << "The first option must be a number. The second option must be listed in the help" << endl;
	}

	if ((strcmp (option, "h")) == 0 || (strcmp(option, "--help")) == 0) {

		for (int i = 0; i < count; ++i){
			cout 	<< "h or --help for this menu," << endl
				<< "r or --random for a completely random creature," << endl
				<< "hy or --hybrid for hybrid creature" << endl 
				<< "--horth for a creature with the rules of Horth" << endl
				<< "--yemit for a creature with the rules of Yemit"<< endl
				<< "--ro for a creature with the rules of Ro" << endl
				<< "a or --all for a complete list" << endl
				<< endl;
		}
	//random
	} else if ((strcmp(option, "r" ) == 0) || (strcmp(option, "--random")) == 0) {
		for (int i = 0; i < count; ++i){
			cout 	<< "A " << creature_size[size(eng)]
				<< " " << creature_base[animal(eng)] << "-like "
				<< creature_type_normal[type(eng)]
				<< ", that " << creature_magic_use[magic_use(eng)]
				<< " " << creature_magic_type[magic(eng)]
				<< ". on this creature is a " 
				<< creature_appendage_type[appendage(eng)] << "."
				<< " It has " << creature_skin_type[skin(eng)] << " for skin."
				<< endl; 
		}
	//hybrid
	} else if ((strcmp(option, "hy")) == 0 || (strcmp(option, "--hybrid")) == 0){
		for (int i = 0; i < count; ++i){
			cout	<< "A " << creature_size[size(eng)] << "-sized hybrid between a "
				<< creature_base[animal(eng)] << " and a " << creature_base[animal(eng)]
				<< endl;
		// horth (one of the titans) special settings
		}
	}else if ((strcmp(option, "--horth") == 0)){
		for (int i = 0; i < count; ++i){
			cout	<< "A "  << creature_size[size(eng)]
				<< " "  << creature_base[animal(eng)] 
				<< "-like " << creature_type_normal[type(eng)]
				<< ", that " << creature_magic_use[magic_use(eng)]
				<< " " << creature_magic_type[magic(eng)]
				<< endl;
		}
		// Yemit (one of the titans) special settings
	} else if ((strcmp(option, "--yemit") == 0)){
		for (int i = 0; i < count; ++i){
			cout 	<< "A " << creature_size[size(eng)]
				<< " " << creature_base[animal(eng)]
				<< "-like " << creature_type_extreme[type_extreme(eng)] << ", that "
				<< creature_magic_use[magic_use(eng)]
				<< " " << creature_magic_type[magic(eng)]
				<< ". On this creature is a "
				<< creature_appendage_type[appendage(eng)] << "."
				<< " It has " << creature_skin_type[skin(eng)] << " for skin."
				<< endl;
		}
	} else if ((strcmp(option, "--ro") == 0)){
		for (int i = 0; i < count; ++i){
			cout	<< "A "  << creature_size[size(eng)]
				<< " "  << creature_base[animal(eng)] 
				<< "-like " << creature_type_normal[type(eng)]
				<< ". On this creature is a "
				<< creature_appendage_type[appendage(eng)] << "."
				<< " It has " << creature_skin_type[skin(eng)] << " for skin."
				<< endl;
		}
	} else if ((strcmp(option, "a")) == 0 || (strcmp(option, "--all")) == 0){
		for (int i = 0; i < count; ++i){
			cout << "The full list is:" << endl;
			for (int i = 0; i < creature_size.size() -1; ++i){
			for (int j = 0; j < creature_base.size() -1; ++j){
			for (int k = 0; k < creature_type_extreme.size() -1; ++k){
			for (int l = 0; l < creature_magic_use.size() -1; ++l){
			for (int m = 0; m < creature_magic_type.size() -1; ++m){
			for (int o = 0; o < creature_appendage_type.size() -1; ++o){
			for (int p = 0; p < creature_skin_type.size() -1; ++p){
				cout 	<< "a " << creature_size[i] << "-sized "
					<< creature_base[j] << "-like "
					<< creature_type_extreme[k]
					<< ", that " << creature_magic_use[l]
					<< " " << creature_magic_type[m]
					<< ". On this creature is a " 
					<< creature_appendage_type[o] << ","
					<< " It has " << creature_skin_type[p] << " for skin."
					<< endl;
			}
			}
			}
			}
			}
			}
			}
		}
	}
}
