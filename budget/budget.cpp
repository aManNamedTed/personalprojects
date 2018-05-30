                <div className="section-desc">
                    After watching <a href="https://www.youtube.com/channel/UCu3DXINXASlKe_HGwEZd4zg" target="_blank">gbay100's</a> video,
                    <a href="https://www.youtube.com/watch?v=CJMUidRAk8E" target="_blank"> <i>What Every Young Person Should Know About Investing And Finance.</i></a>
                    , I thought I would try to create a simple budget calculator.
                    The goal is to make something that works today, and 
                    then make it pretty over time. So for now, stage one of
                    development is to make it just work, with numbers only. Then
                    later I can make graphs and charts similar to the compound 
                    interest website in the video.

                    For now here are the points that gbay touches on in order:
                    <ol>
                        <li>
                            Save $1000 for a rainy day fund.
                        </li>
                        <li>
                            Pay off your debt starting with the highest interest rate.
                        </li>
                        <li>
                            Save up to 3-6 months of expenses.
                        </li>
                        <li>
                            Utilize tax advantage accounts such as 401k or IRA.
                        </li>
                        <li>
                            Save your age in bonds.
                        </li>
                    </ol>
                    Feel free play around with the calculations below. For the
                    sake of a disclaimer, I do not save any of the data that is
                    input below. <br/><br/>

                    <form onSubmit={this.handleSubmit}>
                        <label>
                            Total:
                            <input type="text" value={this.state.total}
                                placeholder="Total"
                                onChange={this.handleChange}
                            />
                        </label>

                        <br/><br/>
                        <input type="submit" value="Submit" />
                    </form>

            gain:
                paychecks monthly = 3200/month
                miscellaneous gains, negligible
                gifts
            loss:   
                student loans = 50/month
                car loans     = 50/month
                credit cards  = ?? (let credit cards = 0, )
                mortgage/rent = 1200/month,. if(mortgage > paycheck/(1/3), careful, over 33% paycheck)
                stocks        = 10/month

            trackTheseVars:
                total 
                totalMoneySaved = (budget->gain * .10 / month)

                stepOne = save 1000 dollars for a rainy day fund
                stepTwo = start paying off your debt where you have a higher interst rate first
                stepThree = save up to 3-6 months of expenses
                                    put this in terms of monthly amounts
                                    1 month: 4000
                                    2 months: 8000
                                    3 months: 12000
                                    etc
                                define budget stuff
                                    food
                                    car
                                    insurance
                stepFour = take advantage of tax advantage accounts 401k, ira  
                stepFive = save your age in bonds
                    </div>
