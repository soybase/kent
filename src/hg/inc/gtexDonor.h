/* gtexDonor.h was originally generated by the autoSql program, which also 
 * generated gtexDonor.c and gtexDonor.sql.  This header links the database and
 * the RAM representation of objects. */

#ifndef GTEXDONOR_H
#define GTEXDONOR_H

#define GTEXDONOR_NUM_COLS 4

extern char *gtexDonorCommaSepFieldNames;

struct gtexDonor
/* GTEx donor (subject) description */
    {
    struct gtexDonor *next;  /* Next in singly linked list. */
    char *name;	/* GTEX subject identifier (minus leading GTEX-), e.g. N7MS */
    char *gender;	/* Gender (M/F) */
    unsigned age;	/* Subject age, to the decade (60 means 60-69 yrs) */
    int deathClass;	/* Hardy scale: 0=Ventilator, 1=Fast violent, 2=Fast natural, 3=Intermediate, 4=Slow.  -1 for unknown */
    };

void gtexDonorStaticLoad(char **row, struct gtexDonor *ret);
/* Load a row from gtexDonor table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct gtexDonor *gtexDonorLoad(char **row);
/* Load a gtexDonor from row fetched with select * from gtexDonor
 * from database.  Dispose of this with gtexDonorFree(). */

struct gtexDonor *gtexDonorLoadAll(char *fileName);
/* Load all gtexDonor from whitespace-separated file.
 * Dispose of this with gtexDonorFreeList(). */

struct gtexDonor *gtexDonorLoadAllByChar(char *fileName, char chopper);
/* Load all gtexDonor from chopper separated file.
 * Dispose of this with gtexDonorFreeList(). */

#define gtexDonorLoadAllByTab(a) gtexDonorLoadAllByChar(a, '\t');
/* Load all gtexDonor from tab separated file.
 * Dispose of this with gtexDonorFreeList(). */

struct gtexDonor *gtexDonorCommaIn(char **pS, struct gtexDonor *ret);
/* Create a gtexDonor out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new gtexDonor */

void gtexDonorFree(struct gtexDonor **pEl);
/* Free a single dynamically allocated gtexDonor such as created
 * with gtexDonorLoad(). */

void gtexDonorFreeList(struct gtexDonor **pList);
/* Free a list of dynamically allocated gtexDonor's */

void gtexDonorOutput(struct gtexDonor *el, FILE *f, char sep, char lastSep);
/* Print out gtexDonor.  Separate fields with sep. Follow last field with lastSep. */

#define gtexDonorTabOut(el,f) gtexDonorOutput(el,f,'\t','\n');
/* Print out gtexDonor as a line in a tab-separated file. */

#define gtexDonorCommaOut(el,f) gtexDonorOutput(el,f,',',',');
/* Print out gtexDonor as a comma separated list including final comma. */

/* -------------------------------- End autoSql Generated Code -------------------------------- */

void gtexDonorCreateTable(struct sqlConnection *conn, char *table);
/* Create donor record format table */

#endif /* GTEXDONOR_H */
