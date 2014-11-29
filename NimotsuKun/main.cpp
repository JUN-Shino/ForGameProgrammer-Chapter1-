#include <iostream>
using namespace std;

//#�� _��� .�S�[�� o�u���b�N p�l
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

//�֐��v���g�^�C�v
void initialize( Object* state, int w, int h, const char* stageData );
void draw( const Object* state, int w, int h );
void update( Object* state, char input, int w, int h );
bool checkClear( const Object* state, int w, int h );


int main(){
	//��Ԕz��m��
	Object* state = new Object[gStageWidth * gStageHeight];
	//�X�e�[�W������
	initialize(state, gStageWidth, gStageHeight, gStageData);

	//���C�����[�v
	while (true){
		//�܂��`��
		draw(state, gStageWidth, gStageHeight);
		//�N���A�`�F�b�N
		if (checkClear(state, gStageWidth, gStageHeight)){
			break;//�N���A�`�F�b�N
		}
		//���͎擾
		cout << "a:left S:right w:up z:down. command?" << endl;//�������
		char input;
		cin >> input;
		//�X�V
		update(state, input, gStageWidth, gStageHeight);
	}
	//�j���̃��b�Z�[�W
	cout << "Congratulation's! you won." << endl;
	//��n��
	delete[] state;
	state = 0;

	//VS�p
	while (true){
		;
	}
	return 0;
}

//---------------------�ȉ��֐���`--------------------

void initialize(Object* state, int width, int/*height*/, const char* stageData){
	const char * d = stageData; //�ǂݍ��݃|�C���^
	int x = 0;
	int y = 0;
	while (*d != '\0'){ //NULL�����łȂ���
		Object t;
		switch (*d){
		case '#': t = OBJ_WALL; break;
		case ' ': t = OBJ_SPACE; break;
		case 'o': t = OBJ_BLOCK; break;
		case 'O': t = OBJ_BLOCK_ON_GOAL; break;
		case '.': t = OBJ_GOAL; break;
		case 'p': t = OBJ_MAN; break;
		case 'P': t = OBJ_MAN_ON_GOAL; break;

		case '\n':  //���̍s��
			x = 0; //x�����[�ɖ߂�
			++y; //y��1�i����
			t = OBJ_UNKNOWN;
			break;

		default: t = OBJ_UNKNOWN; break; //�s���f�[�^
		}
		++d;
		if (t != OBJ_UNKNOWN){
			state[y*width + x] = t;
			++x;
		}

	}

}




