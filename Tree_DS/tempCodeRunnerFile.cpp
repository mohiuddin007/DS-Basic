 int delVal;
    cin>>delVal;
    allNodes = deletionBST(allNodes[0], delVal);
    cout<<"after deletion: ";
    printTree(allNodes[0], 0);