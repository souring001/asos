void io_hlt(void);
void write_mem8(int addr, int data);

void HariMain(void)
{
	int i; /* �ϐ��錾�Bi�Ƃ����ϐ��́A32�r�b�g�̐����^ */
	char *p;


	// for (i = 0xa0000; i <= 0xaffff; i++) {
	// 	 p = (char *)i; /* c */
	// 	 *p = i & 0xf;
	//
	// 	// write_mem8(i, i & 0xf); /* b */
	// }

	p = 0xa0000;
	for (i = 0; i <= 0xffff; i++) {
		p[i] = i & 0xf; /* e */
		// *(p + i) = i & 0xf; /* d */
	}

	for (;;) {
		io_hlt();
	}
}
