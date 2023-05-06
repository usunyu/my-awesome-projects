from pathlib import Path
import zipfile, json

nb = Path("notebooks")

## replace these
user = "jesperdramsch"
folder = "notebooks"
repo = "skillshare-data-science"
github_stem = "jesperdramsch/" + repo + "/"
github_nb = "blob/main/" + folder + "/"
github_url = "https://github.com/"
colab_url = "https://colab.research.google.com/github/"

chapters = {
    "0": "Data Loading",
    "1": "Data Cleaning",
    "2": "Exploratory Data Analysis",
    "3": "Machine Learning",
    "4": "Machine Learning Validation",
    "5": "Data Visualization",
    "6": "Report Generation",
}

current = None

## Head
string = f"""# Skillshare Data Science and Business Analytics in Python
[Skillshare - Data Science and Business Analytics with Python](https://dramsch.net/course1)\n
Free Trial of Skillshare Premium for this course and many many others\n
[![](img/skillshare-x-data-science.png)](https://dramsch.net/course1)\n
Download [all Code]({github_url}{github_stem}archive/main.zip) or [only Notebooks]({github_url}{github_stem}{github_nb[:-1]}.zip)\n\n
Read the notebooks online on: [Data-Science-Gui.de](https://data-science-gui.de).\n\n"""

## TOC

string += "Table of Contents\n---\n\n- [Description](#description)\n- [Data](#data)\n- [Notebooks](#notebooks)\n"
for num in range(7):
    string += f"  {1+num}. [{chapters[str(num)]}](#{chapters[str(num)].lower().replace(' ','-')})\n"
string += "- [Class Project](#class-project)\n\n---\n"

## Description
string += """## Description\n
Machine learning and data science have become important skills across all industries. Knowing both how to perform analytics, as well as, sense checking analyses and understanding concepts is key in making decisions today.\n
Python has become the lingua franca of data science and is, therefore, the topic of this class.\n
Programming can be intimidating, however, Python excels due to its readability and being freely available for all platforms including Linux, Mac and Windows. This class will assume some prior knowledge of Python syntax, but to establish a common learning environment some of the basics will be covered. We will cover the full data science workflow including:\n
- Loading data from files (e.g. Excel tables) and databases (e.g. SQL servers)
- Data cleaning
- Exploratory data analysis
- Machine learning
- Model validation and churn analysis
- Data visualization and report generation\n
In this class we will  use freely and openly available Python libraries including: Jupyter, NumPy, SciPy, Pandas, MatPlotLib, Seaborn, and Scikit-Learn and you will also learn how to quickly learn new libraries.\n\n
"""

## Data
string += """## Data\n
The original data is collected in\n
> Pace, R. Kelley, and Ronald Barry. "Sparse spatial autoregressions." Statistics & Probability Letters 33.3 (1997): 291-297.\n
Modifications were made by\n
> Géron, Aurélien. Hands-on machine learning with Scikit-Learn, Keras, and TensorFlow: Concepts, tools, and techniques to build intelligent systems. O'Reilly Media, 2019.\n
made available under the CC0 license on [Kaggle](https://www.kaggle.com/camnugent/california-housing-prices), with the following modifications from the original:\n

- 207 values were randomly removed from the total_bedrooms column, so we can discuss what to do with missing data.\n
- An additional categorical attribute called ocean_proximity was added, indicating (very roughly) whether each block group is near the ocean, near the Bay area, inland or on an island. This allows discussing what to do with categorical data.\n
"""
## Add a Binder link once
## Notebooks (and zip)
string += f"""## Notebooks\n
[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/{user}/{repo}/HEAD)\n
Click the "notebook" badge to view or the "colab" badge to try out the notebooks interactively.\n
"""

## Each individual notebook
with zipfile.ZipFile("notebooks.zip", "w", zipfile.ZIP_DEFLATED) as ziph:
    for f in sorted(nb.glob("*.ipynb")):
        title = f.stem
        file_name = f.name.replace(" ", "%20")
        colab_link = colab_url + github_stem + github_nb + file_name

        if not str(current) == title[0]:
            current = title[0]
            string += f"## {chapters[current]}\n"

        with open(f, encoding="utf8") as json_file:
            data = json.load(json_file)

        add_ress = "".join(data["cells"][-1]["source"][1:]).strip()

        ziph.write(f)
        string += f"""### {title.split("- ")[1]}\n
[![](https://img.shields.io/badge/view-notebook-orange)]({folder}/{file_name}) [![](https://img.shields.io/badge/open-colab-yellow)](https://colab.research.google.com/github/{user}/{repo}/blob/main/{folder}/{file_name}) [![Gradient](https://assets.paperspace.io/img/gradient-badge.svg)](https://console.paperspace.com/github/{user}/{repo}/blob/main/{folder}/{file_name}) [![Open In SageMaker Studio Lab](https://studiolab.sagemaker.aws/studiolab.svg)](https://studiolab.sagemaker.aws/import/github/{user}/{repo}/blob/main/{folder}/{file_name}) [![Launch in Deepnote](https://deepnote.com/buttons/launch-in-deepnote-small.svg)](https://deepnote.com/launch?url=https%3A%2F%2Fgithub.com%2F{user}%2F{repo}%2Fblob%2Fmain%2F{folder}%2F{file_name})\n
{"".join(data["cells"][0]["source"][1:]).strip()}
{"#### Additional Resources" if add_ress else ""}
{add_ress}
"""
    # Add other files to zip
    ziph.write(Path("notebooks/environment.yml"))
    for f in Path(nb, "data").glob("*"):
        ziph.write(f, Path("notebooks", "data", f.name))


## Class Project
string += """## Class Project\n
[![](img/thumbnail.png)](https://dramsch.net/course1)\n
Create a PDF report of a data analysis in Python with at least one visualization.\n
**Assignment:** Use a dataset you have from a project you are working on. Prepare and analyze this data and create at least one meaningful visualization. The data could be sales, expenses, or your FitBit data! Make sure to anonymize the data in case anything is sensitive information! (If you don’t have any data, I have some data listed and even a data set you can use below!)\n
**Deliverable:** Create a Jupyter Notebook describing your analysis process that contains at least one visualization that tells a compelling story.\n
**Details:** The project will consist of loading data and performing the exploratory data analysis and visualizations outlined in the class. The project is relatively straight-forward, as the class will follow an applied structure that can be revisited for parts of the project analysis.\n
Students are encouraged to use their own datasets for the analysis, as these yield the most benefit in learning. Alternatively, it is also possible to search for data sets in the following places:\n
- OpenML: <https://www.openml.org/search?type=data>
- Google: <https://datasetsearch.research.google.com/>
- Amazon: <https://registry.opendata.aws/>
- Kaggle: <https://www.kaggle.com/datasets>
- Awesome Data: <https://github.com/awesomedata/awesome-public-datasets>\n
In addition, to encourage sharing, I will provide one example data set on Skillshare, where people can explore and apply the learnings from this class. This dataset contains California Housing Sales from the 1990 census.\n
Help each other! Data science thrives from collaboration. Students are encouraged to learn from each other and give feedback on tips and tricks they found during their own analysis. Use the project tab early and often and also check what others have accomplished and leave feedback and likes.\n
Installing all the libraries: When you have conda installed, you can easily use the environment.yml in the notebooks.zip it contains all libraries. Open it with a text editor to see the command to get the environment set up.\n
### [Sign Up here](https://dramsch.net/course1)\n
"""


with open("Readme.md", mode="w", encoding="utf-8") as f:
    f.write(string)
