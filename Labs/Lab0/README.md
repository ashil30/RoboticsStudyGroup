## Working with Jupyter Notebook files on GitHub
* When you add Jupyter Notebook or IPython Notebook files with a .ipynb extension on GitHub, they will render as static HTML files in your repository.

* The interactive features of the notebook, such as custom JavaScript plots, will not work in your repository on GitHub. For an example, see Linking and Interactions.ipynb.

* To view your Jupyter notebook with JavaScript content rendered or to share your notebook files with others you can use nbviewer. For an example, see Linking and Interactions.ipynb rendered on nbviewer.

* To view a fully interactive version of your Jupyter Notebook, you can set up a notebook server locally. For more information, see Jupyter's official documentation.

### Troubleshooting
If you're having trouble rendering Jupyter Notebook files in static HTML, you can convert the file locally on the command line by using the nbconvert command:
``` bash
jupyter nbconvert --to html NOTEBOOK-NAME.ipynb
```


#### Further reading 
1. [Jupyter Notebook's GitHub repository](https://github.com/jupyter/notebook)
2. [Gallery of Jupyter Notebooks](https://github.com/jupyter/jupyter/wiki/A-gallery-of-interesting-Jupyter-Notebooks)
