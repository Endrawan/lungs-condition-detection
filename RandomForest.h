#pragma once
// #include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class RandomForest {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        uint8_t votes[3] = { 0 };
                        // tree #1
                        if (x[0] <= 213.5) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[5] <= 24.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[1] <= 202.5) {
                                    if (x[4] <= 36.95000076293945) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[2] += 1;
                                }
                            }
                        }

                        // tree #2
                        if (x[3] <= 95.5) {
                            if (x[2] <= 175.5) {
                                if (x[4] <= 36.85000038146973) {
                                    votes[0] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                if (x[1] <= 234.5) {
                                    if (x[2] <= 185.0) {
                                        if (x[5] <= 33.5) {
                                            if (x[2] <= 181.5) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[0] += 1;
                                        }
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    if (x[1] <= 236.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }
                            }
                        }

                        else {
                            votes[0] += 1;
                        }

                        // tree #3
                        if (x[3] <= 94.5) {
                            if (x[1] <= 165.0) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[4] <= 37.14999961853027) {
                                    if (x[1] <= 202.5) {
                                        if (x[5] <= 27.5) {
                                            votes[1] += 1;
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            if (x[5] <= 31.0) {
                                votes[2] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        // tree #4
                        if (x[4] <= 36.80000114440918) {
                            if (x[5] <= 34.0) {
                                votes[2] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[1] <= 170.0) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[0] <= 227.5) {
                                    if (x[3] <= 93.5) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #5
                        if (x[0] <= 213.0) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[4] <= 37.14999961853027) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #6
                        if (x[4] <= 36.64999961853027) {
                            if (x[5] <= 33.0) {
                                votes[2] += 1;
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[4] <= 36.95000076293945) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[2] <= 233.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[4] <= 37.75) {
                                        votes[2] += 1;
                                    }

                                    else {
                                        votes[1] += 1;
                                    }
                                }
                            }
                        }

                        // tree #7
                        if (x[5] <= 36.5) {
                            if (x[4] <= 36.95000076293945) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[0] <= 227.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            votes[0] += 1;
                        }

                        // tree #8
                        if (x[4] <= 36.75) {
                            if (x[3] <= 94.5) {
                                if (x[5] <= 35.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                votes[0] += 1;
                            }
                        }

                        else {
                            if (x[0] <= 226.0) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #9
                        if (x[2] <= 185.5) {
                            if (x[4] <= 36.85000038146973) {
                                if (x[5] <= 34.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[0] += 1;
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            if (x[0] <= 226.5) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #10
                        if (x[0] <= 211.5) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[4] <= 37.14999961853027) {
                                if (x[1] <= 183.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    if (x[1] <= 196.0) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #11
                        if (x[1] <= 171.5) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[4] <= 37.14999961853027) {
                                if (x[5] <= 25.5) {
                                    if (x[3] <= 94.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }

                                else {
                                    if (x[5] <= 41.5) {
                                        if (x[5] <= 27.5) {
                                            if (x[4] <= 36.60000038146973) {
                                                votes[2] += 1;
                                            }

                                            else {
                                                votes[1] += 1;
                                            }
                                        }

                                        else {
                                            votes[2] += 1;
                                        }
                                    }

                                    else {
                                        votes[0] += 1;
                                    }
                                }
                            }

                            else {
                                if (x[2] <= 240.0) {
                                    votes[1] += 1;
                                }

                                else {
                                    if (x[1] <= 236.5) {
                                        votes[1] += 1;
                                    }

                                    else {
                                        votes[2] += 1;
                                    }
                                }
                            }
                        }

                        // tree #12
                        if (x[0] <= 213.0) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[0] <= 226.0) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        // tree #13
                        if (x[5] <= 33.5) {
                            if (x[0] <= 226.5) {
                                votes[2] += 1;
                            }

                            else {
                                votes[1] += 1;
                            }
                        }

                        else {
                            votes[0] += 1;
                        }

                        // tree #14
                        if (x[5] <= 36.5) {
                            if (x[5] <= 31.5) {
                                if (x[0] <= 222.0) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }

                            else {
                                votes[2] += 1;
                            }
                        }

                        else {
                            votes[0] += 1;
                        }

                        // tree #15
                        if (x[0] <= 213.0) {
                            votes[0] += 1;
                        }

                        else {
                            if (x[5] <= 26.5) {
                                votes[1] += 1;
                            }

                            else {
                                if (x[0] <= 233.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        // tree #16
                        if (x[5] <= 36.5) {
                            if (x[0] <= 226.5) {
                                votes[2] += 1;
                            }

                            else {
                                if (x[3] <= 93.5) {
                                    votes[2] += 1;
                                }

                                else {
                                    votes[1] += 1;
                                }
                            }
                        }

                        else {
                            votes[0] += 1;
                        }

                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 3; i++) {
                            if (votes[i] > maxVotes) {
                                classIdx = i;
                                maxVotes = votes[i];
                            }
                        }

                        return classIdx;
                    }

                protected:
                };
            }
        }
    }
