#include "flite.h"
#include "cst_utterance.h"
#include "stdio.h"

int main()
{
    cst_utterance* utt=new_utterance();

    feat_set_string(utt->features,"feat","featvalue");
    printf("%s\n",val_string(feat_val(utt->features,"feat")));
    
    cst_relation* token_r = utt_relation_create(utt,"Token");


    cst_item* token1=relation_append(token_r,NULL);
    item_set_string(token1,"name","我今天");

    cst_item* token2=relation_append(token_r,NULL);
    item_set_string(token2,"name","很高兴");


    cst_relation* word_r=utt_relation_create(utt,"Word");

    cst_item* token_p=relation_head(token_r);

    cst_item* t1_w1=item_add_daughter(token_p,NULL);
    item_set_string(t1_w1,"name","我");
    relation_append(word_r,t1_w1);

    cst_item* t1_w2=item_add_daughter(token_p,NULL);
    item_set_string(t1_w2,"name","今天");
    relation_append(word_r,t1_w2);

    token_p=item_next(token_p);
    cst_item* t2_w1=item_add_daughter(token_p,NULL);
    item_set_string(t2_w1,"name","很");
    relation_append(word_r,t2_w1);

    cst_item* t2_w2=item_add_daughter(token_p,NULL);
    item_set_string(t2_w2,"name","高兴");
    relation_append(word_r,t2_w2);


    
    printf("Tokens:\n");
    for(token_p=relation_head(utt_relation(utt,"Token"));token_p;token_p=item_next(token_p))   
    {
        printf("%s\n",item_feat_string(token_p,"name"));
        printf("%x %x\n",item_daughter(token_p),item_last_daughter(token_p));
    }


    printf("Words:\n");
    cst_item* word_p;
    for(word_p=relation_head(utt_relation(utt,"Word"));word_p;word_p=item_next(word_p))   
    {
        printf("%s\t parent \n",item_feat_string(word_p,"name"));//,item_feat_string(item_parent(item),"name"));
        cst_item* tmp=item_as(word_p,"Token");
        printf("%x \t %x \t %d\n",word_p,tmp,item_parent(tmp));
    }


    printf("%x\t%x\t%x\n",token1,utt_relation(utt,"Word"),relation_head(utt_relation(utt,"Word")));

    //cst_relation* r2 = utt_relation_create(utt,"R2");
    printf("%x %s\n",token1,item_feat_string(t1_w2,"name"));
    printf("%x %s\n",token1,item_feat_string(item_as(t1_w2,"Token"),"name"));

    return 0;
}
