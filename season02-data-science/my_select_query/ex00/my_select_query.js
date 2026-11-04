class MySelectQuery {
    constructor(csv_content) {
      const lines = csv_content.trim().split('\n');
      this.headers = lines.shift().split(',');
      this.colIndex = this.headers.reduce((acc, name, i) => {
        acc[name] = i;
        return acc;
      }, {});
      this.dataLines = lines;
      this.dataFields = lines.map(line => line.split(','));
    }
  
    where(column_name, criteria) {
      const idx = this.colIndex[column_name];
      if (idx === undefined) return [];
      return this.dataLines.filter((line, i) =>
        this.dataFields[i][idx] === criteria
      );
    }
  }
  
  module.exports = MySelectQuery;
  