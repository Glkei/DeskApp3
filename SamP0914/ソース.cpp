#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <istream> 
#include <sstream> // ������̑���

//���i���
struct item {
	std::string name; //���i��
	int price; //���z
	int category; //�J�e�S��
	int quantity; //��
};

//�J�e�S���̓o�^
std::vector<std::string> catName{
	{"�H�i"},
	{"����"},
	{"���[��"},
	{"�{"},
	{"�G��"}
};

//�����̏��i�o�^
std::vector<item> product{
	//{"���i��",���z,�J�e�S��,��}
	{"���ɂ���(�c�i)",120,0,10},
	{"���ɂ���(��)",120,0,10},
	{"�I�����W�W���[�X",100,1,10},
	{"���M(��)",50,2,10},
	{"�����S���i���j",50,2,10},
};

//���i�ꗗ
void productListView() {
	std::cout << "���i�ꗗ�\��\n";

	for (int i = 0; i < product.size(); i++) {
		std::cout << product[i].name << "\t";
		std::cout << product[i].price << "�~\t";
		std::cout << product[i].category << "\t";
		std::cout << product[i].quantity << "��";
		std::cout << "\n";
	}
};

//yomi
std::vector<std::string> split(std::string input, char delimiter)
{
	std::istringstream stream(input);
	std::string field;
	std::vector<std::string> result;
	while (getline(stream, field, delimiter)) {
		result.push_back(field);
	}
	return result;
}

//�ǂݍ���
void load() {
	std::string fileName = "data.txt";
	std::ifstream ifs(fileName);

	if (!ifs) {
		std::cout << "�t�@�C�����J���܂���B";
	}
	else {
		std::cout << "�Ǎ��J�n\n";
		product.clear();


		// csv�f�[�^��1�s���ǂݍ���
		std::string line;
		while (getline(ifs, line)) {
			//std::cout << line << "\n";
			//1�s�̒��̃J���}���Ƃɕ������Ă���
			std::vector<std::string> strvec = split(line, ',');
			/*
				std::string name; //���i��
				int price; //���z
				int category; //�J�e�S��
				int quantity; //��
			*/
			std::cout << strvec[0] << "\n";
			product.push_back({
				strvec[0], // ���i��
				std::atoi(strvec[1].c_str()), // ���z
				std::atoi(strvec[2].c_str()), // �J�e�S��
				std::atoi(strvec[3].c_str()),  // ��
				});
		}
		std::cout << "�Ǎ�����\n";
	}
}//load done

//�ۑ�
void save() {
	std::string fileName = "data.txt";
	std::ofstream ofs(fileName);

	if (!ofs) {
		std::cout << "�t�@�C�����J���܂���";
	}
	else {
		std::cout << "�ۑ��J�n";

		ofs << "�e�X�g�ۑ�";

		for (int i = 0; i < product.size(); i++) {
			ofs
				<< product[i].name << "."
				<< product[i].price << "."
				<< product[i].category << "."
				<< product[i].quantity << ".";
		}

		std::cout << "�ۑ�����";
	}

}

//���i�o�^ done
void addItem() {
	std::string name; //���i��
	int price; //���z�i�Ŕ����j
	int category; //�J�e�S��
	int quantity; //��

	std::cout << "���i���F";
	std::cin >> name;

	std::cout << "���z";
	std::cin >> price;

	//�J�e�S���[�ꗗ�̕\��
	for (int i = 0; i < catName.size(); i++) {
		std::cout << catName[i] << ":" << i << "\n";
	}
	std::cout << "�J�e�S���F";
	std::cin >> category;

	std::cout << "���F";
	std::cin >> quantity;

	//���i�̒ǉ�
	product.push_back(
		{ name,price,category,quantity }
	);

	std::cout << "�o�^����\n";
}

//���i�̍폜 done
void deleteItem() {
	//���i�ꗗ�̕\��
	int num;
	for (int i = 0; i < product.size(); i++) {
		std::cout << i << product[i].name << "\n";
	}
	std::cout << "�폜����ԍ���I���F";
	std::cin >> num;

	//�폜�̎��s
	product.erase(product.begin() + num);
	std::cout << "�폜���܂���\n\n";


}

//���i�̕ҏW done
void editItem() {
	int num;
	for (int i = 0; i < product.size(); i++) {
		std::cout << i << product[i].name << "\n";
	}
	std::cout << "�ҏW����ԍ���I���F";
	std::cin >> num;

	//���i��
	std::cout << "\n���i���F" << product[num].name << "\n\n";
	std::cin >> product[num].name;

	//���z
	std::cout << "\n���z�F" << product[num].price << "\n\n";
	std::cin >> product[num].price;

	//�J�e�S��
	for (int i = 0; i < catName.size(); i++) {
		std::cout << i << ":" << catName[i] << "\n\n";
	}
	std::cout << "\n�J�e�S���F" << product[num].category << "\n\n";
	std::cin >> product[num].category;

	//��
	std::cout << "\n���F" << product[num].quantity << "\n\n";
	std::cin >> product[num].quantity;

}

//���C��
int main() {
	std::cout << "���i�Ǘ��V�X�e��\n";
	int selector = 0;

	while (selector != 99) {
		std::cout << "�ꗗ:0  \n"
			<< "�Ǎ�:8 �ۑ�:9 \n"
			<< "�ǉ��F55 �@�ҏW :66 \n"
			<< "�폜�F88  �I��:99\n�F";
		std::cin >> selector;
		system("cls");//��ʃN���A

		switch (selector)
		{
		case 0: productListView(); break;
		case 8: load(); break;
		case 9: save(); break;
		case 55: addItem(); break;
		case 66: editItem(); break;
		case 88: deleteItem(); break;
		default: selector = 99;  break;
		}
	}


	system("pause");
	return 0;
}