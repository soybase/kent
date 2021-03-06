/* wgEncodeCell.h was originally generated by the autoSql program, which also 
 * generated wgEncodeCell.c and wgEncodeCell.sql.  This header links the database and
 * the RAM representation of objects. */

#ifndef WGENCODECELL_H
#define WGENCODECELL_H

#define WGENCODECELL_NUM_COLS 14

extern char *wgEncodeCellCommaSepFieldNames;

struct wgEncodeCell
/* Cell types used by ENCODE (2007-2012) */
    {
    struct wgEncodeCell *next;  /* Next in singly linked list. */
    unsigned id;	/* internal id */
    char *term;	/* public identifier */
    char *description;	/* descriptive phrase */
    char *tissue;	/* organ, anatomical site */
    char *type;	/* tissue, cell line, or differentiated */
    char *cancer;	/* cancer or normal */
    char *developmental;	/* cell lineage */
    char *sex;	/* M, F, or U for unknown */
    char *vendor;	/* name of vendor or lab provider */
    char *vendorId;	/* vendor product code or identifier */
    char *url;	/* order URL or protocol document */
    char *ontoTerm;	/* ontology term */
    char *btOntoTerm;	/* ontology term from Brenda Tissue Ontology */
    char *donor;	/* donor accession at encodeproject.org */
    };

void wgEncodeCellStaticLoad(char **row, struct wgEncodeCell *ret);
/* Load a row from wgEncodeCell table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct wgEncodeCell *wgEncodeCellLoad(char **row);
/* Load a wgEncodeCell from row fetched with select * from wgEncodeCell
 * from database.  Dispose of this with wgEncodeCellFree(). */

struct wgEncodeCell *wgEncodeCellLoadAll(char *fileName);
/* Load all wgEncodeCell from whitespace-separated file.
 * Dispose of this with wgEncodeCellFreeList(). */

struct wgEncodeCell *wgEncodeCellLoadAllByChar(char *fileName, char chopper);
/* Load all wgEncodeCell from chopper separated file.
 * Dispose of this with wgEncodeCellFreeList(). */

#define wgEncodeCellLoadAllByTab(a) wgEncodeCellLoadAllByChar(a, '\t');
/* Load all wgEncodeCell from tab separated file.
 * Dispose of this with wgEncodeCellFreeList(). */

struct wgEncodeCell *wgEncodeCellCommaIn(char **pS, struct wgEncodeCell *ret);
/* Create a wgEncodeCell out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new wgEncodeCell */

void wgEncodeCellFree(struct wgEncodeCell **pEl);
/* Free a single dynamically allocated wgEncodeCell such as created
 * with wgEncodeCellLoad(). */

void wgEncodeCellFreeList(struct wgEncodeCell **pList);
/* Free a list of dynamically allocated wgEncodeCell's */

void wgEncodeCellOutput(struct wgEncodeCell *el, FILE *f, char sep, char lastSep);
/* Print out wgEncodeCell.  Separate fields with sep. Follow last field with lastSep. */

#define wgEncodeCellTabOut(el,f) wgEncodeCellOutput(el,f,'\t','\n');
/* Print out wgEncodeCell as a line in a tab-separated file. */

#define wgEncodeCellCommaOut(el,f) wgEncodeCellOutput(el,f,',',',');
/* Print out wgEncodeCell as a comma separated list including final comma. */

/* -------------------------------- End autoSql Generated Code -------------------------------- */

#endif /* WGENCODECELL_H */

