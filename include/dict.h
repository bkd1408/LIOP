
#ifndef _DICT_H_
#define	_DICT_H_

#define ENDSTRING			0xFFFF

/************************************************************************************************/
/* structure for object dictionary																*/
/************************************************************************************************/
const struct _dict
{
	WORD object;
	BYTE sub;
	BYTE access;
	BYTE size;
	void * pointer;
};
extern const struct _dict dict[];

DWORD read_dict (BYTE pos, BYTE subindex);
BYTE write_dict (BYTE pos, BYTE subindex, DWORD value);
DWORD search_dict (WORD index, BYTE subindex, BYTE type, BYTE * pos);


#endif

