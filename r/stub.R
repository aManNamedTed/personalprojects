labelledSentences = read.table(file=yelp_labelled,
                               header=T, sep=" ", na.strings="'",
                               stringAsFactors=F
                              )

sentenceData = labelledSentences[,c("SENTENCES", "SENTIMENT")]

png(file="labelledSentenceData.png")
plot(x=sentenceData$SENTENCES, y=sentenceData$SENTIMENT,
     xlab="Sentences", ylab="Sentiment", main="Sentences and Sentiments"
    )
