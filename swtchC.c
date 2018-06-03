#include"swtch.h"

struct context* mkcontext(void (*func)(),void* stack,int stacksize){
	//与えられた関数を実行するコンテキストを作成する。
	struct context* c;
	void* sp = stack;
	sp += stacksize;
	sp = (void*)((QWORD)sp - (QWORD)sp % 0x10);	//スタックのアライメント調整
	sp -= sizeof(struct context)+0x8;		//コンテキスト保存用の領域を開ける。(アライメント調整のため0x8を足している)
	c = (struct context*)sp;
	c->rip = (QWORD)func;
	c->rbp = (QWORD)stack + stacksize;		//一応ベースポインタをスタックの底にセットしてみる
	c->rbp -= c->rbp % 0x10;
	return c;
}
