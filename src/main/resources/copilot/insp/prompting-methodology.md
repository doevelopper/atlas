Iterate until you have to revert
The output of Language Models is like a decision tree with thousands of possible outcomes. Each word predicted by the model branches out into a set of new possibilities, most of which are invisible to you. The only part that’s under your control is the starting point — and that’s your prompt.
One major difference between Language Models and decision trees is the presence of randomness. The same prompt doesn’t always generate the same response. It’s the price we pay for creativity.
There’s also the alignment tax, where the model’s behavior (and capability) can change to meet (new) restrictions. And to top things off, nobody really knows what’s happening inside Language Models.
In short, when you use a Language Model, you’re interacting with an unpredictable black box. You can’t really rely on exact science: trial and error is your best option.
The rule is simple: Iterate on your prompt until the latest version of your output becomes worse than the previous one. In other words, iterate until you have to revert.
Iteration comes in two flavors: either try different versions of the same prompt or guide the model through a succession of prompts. In most cases, you’ll use a combination of both.

Illustration of how the quality of your output evolves with prompt iterations.
To better understand how the iterative process works, picture prompting as a concave function (or a bell curve). Your first iterations are likely to get you better results, but at some point, your new prompt will start to generate worse output compared to its predecessors.
Pay attention to the inflection point, and when you reach it, you want to either settle or start a new chain of prompts.

Illustration of how successive chains of prompt iterations can improve your final prompt.
You can use the following framework to get yourself started with the iterative process.
    1. Use Many-Examples prompting to generate ideas.
“Please provide me with a list of 50 suggestions on how to improve this prompt/response.”
    2. Use Prompt Revision/Bernard to improve your prompts.
    3. Rewrite the same prompt using different words and examine the responses. Different words trigger different responses.
    4. Create a library of prompts for each model you use. Make sure to update your library every now and then.
    5. Study how Language Models work to understand how they generate responses.
Whenever your output is stuck in the mud, give your prompts a few tweaks to push it out. Try different verbs. Mix prompting techniques. Switch models. Sleep on it. Start again tomorrow.
