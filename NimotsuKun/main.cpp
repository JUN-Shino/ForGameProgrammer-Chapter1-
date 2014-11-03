#include <iostream>
using namespace std;

//#壁 _空間 .ゴール oブロック p人
const char gStageData[] = "\
########\n\
# .. p #\n\
# oo   #\n\
#      #\n\
########";
const int gStageWidth = 8;
const int gStageHeight = 5;

enum Object{
	OBJ_SPACE,
	OBJ_WALL,
	OBJ_GOAL,
	OBJ_BLOCK,
	OBJ_BLOCK_ON_GOAL,
	OBJ_MAN,
	OBJ_MAN_ON_GOAL,

	OBJ_UNKNOWN,
};

//関数プロトタイプ
void initialize( Object* state, int w, int h, const char* stageData );
void draw( const Object* state, int w, int h );
void update( Object* state, char input, int w, int h );
bool checkClear( const Object* state, int w, int h );


int main(){
	//状態配列確保
	Object* state = new Object[gStageWidth * gStageHeight];
	//ステージ初期化
	initialize(state, gStageWidth, gStageHeight, gStageData);

	//メインループ
	while (true){
		//まず描画
		draw(state, gStageWidth, gStageHeight);
		//クリアチェック
		if (checkClear(state, gStageWidth, gStageHeight)){
			break;//クリアチェック
		}
		//入力取得
		cout << "a:left S:right w:up z:down. command?" << endl;//操作説明
		char input;
		cin >> input;
		//更新
		update(state, input, gStageWidth, gStageHeight);
	}
	//祝いのメッセージ
	cout << "Congratulation's! you won." << endl;
	//後始末
	delete[] state;
	state = 0;

	//VS用
	while (true){
		;
	}
	return 0;
}

//---------------------以下関数定義--------------------

void initialize(Object* state, int width, int/*height*/, const char* stageData){
	const char * d = stageData; //読み込みポインタ
	int x = 0;
	int y = 0;
	while (*d != '\0'){ //NULL文字でない間
		Object t;
		switch (*d){
		case '#':t = OBJ_WALL; break;
		case ' ':t = OBJ_SPACE; break;
	

	}
}




