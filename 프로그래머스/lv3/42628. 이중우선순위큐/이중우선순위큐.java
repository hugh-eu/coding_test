import java.util.*;

class Solution {
    static class HeapMax {
        private ArrayList<Integer> arrMax;

        public HeapMax() {
            arrMax = new ArrayList<>();
            arrMax.add(null);
        }

        public Integer getIdxNum(Integer num) {
            if (num != null) {
                for (int i = 1; i < arrMax.size(); i++) {
                    if (arrMax.get(i).equals(num)) return i;
                }
            }
            return null;
        }

        public int getIdxInput() {
            return arrMax.size();
        }

        public int getIdxParent(int idxChild) {
            return idxChild / 2;
        }

        public int getIdxLeftChild(int idxParent) {
            return idxParent * 2;
        }

        public int getIdxRightChild(int idxParent) {
            return idxParent * 2 + 1;
        }

        public void inputNum(int num) {
            int idxChild = getIdxInput();
            int idxParent = getIdxParent(idxChild);
            arrMax.add(idxChild, num);
            while (idxParent > 0) {
                int numChild = arrMax.get(idxChild);
                int numParent = arrMax.get(idxParent);
                if (numChild > numParent) {
                    arrMax.set(idxChild, numParent);
                    arrMax.set(idxParent, numChild);
                    idxChild = idxParent;
                    idxParent = getIdxParent(idxChild);
                } else break;
            }
        }

        public void delNum(Integer idxParent) {
            if (idxParent != null) {
                arrMax.set(idxParent, arrMax.get(arrMax.size() - 1));
                arrMax.remove(arrMax.size() - 1);
                while (arrMax.size() - 1 >= getIdxLeftChild(idxParent)) {
                    int idxLeftChild = getIdxLeftChild(idxParent);
                    int idxRightChild = getIdxRightChild(idxParent);
                    int numParent = arrMax.get(idxParent);
                    int numLeftChild = arrMax.get(getIdxLeftChild(idxParent));
                    if (arrMax.size() - 1 >= idxRightChild && numLeftChild < arrMax.get(getIdxRightChild(idxParent))) {
                        int numRightChild = arrMax.get(getIdxRightChild(idxParent));
                        if (numParent < numRightChild) {
                            arrMax.set(idxParent, numRightChild);
                            arrMax.set(idxRightChild, numParent);
                            idxParent = idxRightChild;
                        } else break;
                    } else {
                        if (numParent < numLeftChild) {
                            arrMax.set(idxParent, numLeftChild);
                            arrMax.set(idxLeftChild, numParent);
                            idxParent = idxLeftChild;
                        } else break;
                    }
                }
            }
        }

        public Integer getMax() {
            return arrMax.size() > 1 ? arrMax.get(1) : null;
        }

    }

    static class HeapMin {
        private ArrayList<Integer> arrMin;

        public HeapMin() {
            arrMin = new ArrayList<>();
            arrMin.add(null);
        }

        public Integer getIdxNum(Integer num) {
            if (num != null) {
                for (int i = 1; i < arrMin.size(); i++) {
                    if (arrMin.get(i).equals(num)) return i;
                }
            }
            return null;
        }

        public int getIdxInput() {
            return arrMin.size();
        }

        public int getIdxParent(int idxChild) {
            return idxChild / 2;
        }

        public int getIdxLeftChild(int idxParent) {
            return idxParent * 2;
        }

        public int getIdxRightChild(int idxParent) {
            return idxParent * 2 + 1;
        }

        public void inputNum(int num) {
            int idxChild = getIdxInput();
            int idxParent = getIdxParent(idxChild);
            arrMin.add(idxChild, num);
            while (idxParent > 0) {
                int numChild = arrMin.get(idxChild);
                int numParent = arrMin.get(idxParent);
                if (numChild < numParent) {
                    arrMin.set(idxChild, numParent);
                    arrMin.set(idxParent, numChild);
                    idxChild = idxParent;
                    idxParent = getIdxParent(idxChild);
                } else break;
            }
        }

        public void delNum(Integer idxParent) {
            if (idxParent != null) {
                arrMin.set(idxParent, arrMin.get(arrMin.size() - 1));
                arrMin.remove(arrMin.size() - 1);
                while (arrMin.size() - 1 >= getIdxLeftChild(idxParent)) {
                    int idxLeftChild = getIdxLeftChild(idxParent);
                    int idxRightChild = getIdxRightChild(idxParent);
                    int numParent = arrMin.get(idxParent);
                    int numLeftChild = arrMin.get(getIdxLeftChild(idxParent));
                    if (arrMin.size() - 1 >= idxRightChild && numLeftChild > arrMin.get(getIdxRightChild(idxParent))) {
                        int numRightChild = arrMin.get(getIdxRightChild(idxParent));
                        if (numParent > numRightChild) {
                            arrMin.set(idxParent, numRightChild);
                            arrMin.set(idxRightChild, numParent);
                            idxParent = idxRightChild;
                        } else break;
                    } else {
                        if (numParent > numLeftChild) {
                            arrMin.set(idxParent, numLeftChild);
                            arrMin.set(idxLeftChild, numParent);
                            idxParent = idxLeftChild;
                        } else break;
                    }
                }
            }
        }

        public Integer getMin() {
            return arrMin.size() > 1 ? arrMin.get(1) : null;
        }

    }
    
    public int[] solution(String[] operations) {
        HeapMax heapMax = new HeapMax();
        HeapMin heapMin = new HeapMin();
        for (String op : operations) {
            String[] splitOp = op.split(" ");
            if (splitOp[0].equals("I")) {
                heapMax.inputNum(Integer.parseInt(splitOp[1]));
                heapMin.inputNum(Integer.parseInt(splitOp[1]));
            } else if (splitOp[0].equals("D")) {
                if (splitOp[1].equals("1")) {
                    heapMin.delNum(heapMin.getIdxNum(heapMax.getMax()));
                    heapMax.delNum(heapMax.getIdxNum(heapMax.getMax()));
                } else if (splitOp[1].equals("-1")) {
                    heapMax.delNum(heapMax.getIdxNum(heapMin.getMin()));
                    heapMin.delNum(heapMin.getIdxNum(heapMin.getMin()));
                }
            }
        }
        
        return new int[] {heapMax.getMax() != null ? heapMax.getMax() : 0, heapMin.getMin() != null ? heapMin.getMin() : 0};
        
    }
}