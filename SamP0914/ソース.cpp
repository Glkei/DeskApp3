#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <istream> 
#include <sstream> // 文字列の操作

//商品情報
struct item {
	std::string name; //商品名
	int price; //金額
	int category; //カテゴリ
	int quantity; //個数
};

//カテゴリの登録
std::vector<std::string> catName{
	{"食品"},
	{"飲料"},
	{"文房具"},
	{"本"},
	{"雑貨"}
};

//初期の商品登録
std::vector<item> product{
	//{"商品名",金額,カテゴリ,個数}
	{"おにぎり(ツナ)",120,0,10},
	{"おにぎり(鮭)",120,0,10},
	{"オレンジジュース",100,1,10},
	{"鉛筆(黒)",50,2,10},
	{"消しゴム（小）",50,2,10},
};

//商品一覧
void productListView() {
	std::cout << "商品一覧表示\n";

	for (int i = 0; i < product.size(); i++) {
		std::cout << product[i].name << "\t";
		std::cout << product[i].price << "円\t";
		std::cout << product[i].category << "\t";
		std::cout << product[i].quantity << "個";
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

//読み込み
void load() {
	std::string fileName = "data.txt";
	std::ifstream ifs(fileName);

	if (!ifs) {
		std::cout << "ファイルが開けません。";
	}
	else {
		std::cout << "読込開始\n";
		product.clear();


		// csvデータを1行ずつ読み込む
		std::string line;
		while (getline(ifs, line)) {
			//std::cout << line << "\n";
			//1行の中のカンマごとに分解している
			std::vector<std::string> strvec = split(line, ',');
			/*
				std::string name; //商品名
				int price; //金額
				int category; //カテゴリ
				int quantity; //個数
			*/
			std::cout << strvec[0] << "\n";
			product.push_back({
				strvec[0], // 商品名
				std::atoi(strvec[1].c_str()), // 金額
				std::atoi(strvec[2].c_str()), // カテゴリ
				std::atoi(strvec[3].c_str()),  // 個数
				});
		}
		std::cout << "読込完了\n";
	}
}//load done

//保存
void save() {
	std::string fileName = "data.txt";
	std::ofstream ofs(fileName);

	if (!ofs) {
		std::cout << "ファイルが開けません";
	}
	else {
		std::cout << "保存開始";

		ofs << "テスト保存";

		for (int i = 0; i < product.size(); i++) {
			ofs
				<< product[i].name << "."
				<< product[i].price << "."
				<< product[i].category << "."
				<< product[i].quantity << ".";
		}

		std::cout << "保存完了";
	}

}

//商品登録 done
void addItem() {
	std::string name; //商品名
	int price; //金額（税抜き）
	int category; //カテゴリ
	int quantity; //個数

	std::cout << "商品名：";
	std::cin >> name;

	std::cout << "金額";
	std::cin >> price;

	//カテゴリー一覧の表示
	for (int i = 0; i < catName.size(); i++) {
		std::cout << catName[i] << ":" << i << "\n";
	}
	std::cout << "カテゴリ：";
	std::cin >> category;

	std::cout << "個数：";
	std::cin >> quantity;

	//商品の追加
	product.push_back(
		{ name,price,category,quantity }
	);

	std::cout << "登録完了\n";
}

//商品の削除 done
void deleteItem() {
	//商品一覧の表示
	int num;
	for (int i = 0; i < product.size(); i++) {
		std::cout << i << product[i].name << "\n";
	}
	std::cout << "削除する番号を選択：";
	std::cin >> num;

	//削除の実行
	product.erase(product.begin() + num);
	std::cout << "削除しました\n\n";


}

//商品の編集 done
void editItem() {
	int num;
	for (int i = 0; i < product.size(); i++) {
		std::cout << i << product[i].name << "\n";
	}
	std::cout << "編集する番号を選択：";
	std::cin >> num;

	//商品名
	std::cout << "\n商品名：" << product[num].name << "\n\n";
	std::cin >> product[num].name;

	//金額
	std::cout << "\n金額：" << product[num].price << "\n\n";
	std::cin >> product[num].price;

	//カテゴリ
	for (int i = 0; i < catName.size(); i++) {
		std::cout << i << ":" << catName[i] << "\n\n";
	}
	std::cout << "\nカテゴリ：" << product[num].category << "\n\n";
	std::cin >> product[num].category;

	//個数
	std::cout << "\n個数：" << product[num].quantity << "\n\n";
	std::cin >> product[num].quantity;

}

//メイン
int main() {
	std::cout << "商品管理システム\n";
	int selector = 0;

	while (selector != 99) {
		std::cout << "一覧:0  \n"
			<< "読込:8 保存:9 \n"
			<< "追加：55 　編集 :66 \n"
			<< "削除：88  終了:99\n：";
		std::cin >> selector;
		system("cls");//画面クリア

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